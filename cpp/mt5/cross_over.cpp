//+------------------------------------------------------------------+
//|                                                  MAcrossOver.mq5 |
//|                                  Copyright 2025, MetaQuotes Ltd. |
//|                                             https://www.mql5.com |
//+------------------------------------------------------------------+
#property copyright "Copyright 2025, MetaQuotes Ltd."
#property link "https://www.mql5.com"
#property version "1.00"
#include <Trade/Trade.mqh>

// Moving Average handler
int MA7Handle;
int MA14Handle;
double movingAverage7Buffer[];
double movingAverage14Buffer[];

int sevenDays = 7;
int fourteenDays = 14;

// define so trader can use it from input window
input double LotSize = 1; // Lot size for trading

// Take Profit and StopLoss here are in points not in exact value.
// so if _Point is defined 0.01, Stoploss in this case would be 100. (StopLoss *
// _Point))
input double TakeProfit = 10000; // Take profit in points
input double StopLoss = 10000;   // Stop loss in points
CTrade trade;
//+------------------------------------------------------------------+
//| Expert initialization function                                   |
//+------------------------------------------------------------------+
int OnInit() {
  //---
  // create both 7 days and 14 days moving average handler on initialization
  MA7Handle = iMA(_Symbol, PERIOD_D1, sevenDays, 0, MODE_SMA, PRICE_CLOSE);
  MA14Handle = iMA(_Symbol, PERIOD_D1, fourteenDays, 0, MODE_SMA, PRICE_CLOSE);

  // check if moving average didn't failed
  if (MA7Handle == INVALID_HANDLE || MA14Handle == INVALID_HANDLE) {
    printf("Initialization of moving average handler failed");
    return (INIT_FAILED);
  }
  //---
  return (INIT_SUCCEEDED);
}
//+------------------------------------------------------------------+
//| Expert deinitialization function                                 |
//+------------------------------------------------------------------+
void OnDeinit(const int reason) {
  if (MA7Handle != INVALID_HANDLE)
    IndicatorRelease(MA7Handle);
  if (MA14Handle != INVALID_HANDLE)
    IndicatorRelease(MA14Handle);
}

//+------------------------------------------------------------------+
//| Expert tick function                                             |
//+------------------------------------------------------------------+
void OnTick() {
  // int drawMA7 = MA7Handle;
  // int drawMA14 = MA14Handle;
  //---
  //  getting moving average on current bar for last 7 and 14 days.
  //  copy buffer will retrun -1 for error on copy
  int ma7Error = CopyBuffer(MA7Handle, 0, 0, 2, movingAverage7Buffer);
  int ma14Error = CopyBuffer(MA14Handle, 0, 0, 2, movingAverage14Buffer);
  if (ma7Error < 0 || ma14Error < 0) {
    printf("Failed to copy buffer of MA indicator");
    return;
  }

  // We would use most recent completed candle as MA is also calculated based on
  // OHLC.
  double currentBid = SymbolInfoDouble(_Symbol, SYMBOL_BID);
  double currentAsk = SymbolInfoDouble(_Symbol, SYMBOL_ASK);

  double currentMA7 = movingAverage7Buffer[0];
  double currentMA14 = movingAverage14Buffer[0];

  double previousMA7 = movingAverage7Buffer[1];
  double previousMA14 = movingAverage14Buffer[1];

  // Buy signal: - If 7 days MA Upside, then buy
  // In real case this should be compaired with some small value as both are
  // Ex:- (currentMA7 - currentMA14) > delta; // where delta is defined
  // as smallest difference
  if (previousMA7 < previousMA14 && currentMA7 > currentMA14) {
    // open buy position after checking if there are no existing buy position
    // My assumption is to keep buy and sell both open so before buying will not
    // try to sell or vice - versa

    if (!checkIfOpenPositionForType(POSITION_TYPE_BUY)) {
      openAPositionToBuy(currentAsk);
    }
  }

  // Sell signal:- If 7 days MA is downside, then sell
  if (previousMA7 > previousMA14 && currentMA7 < currentMA14) {
    // open sell position after checking if there are no existing sell position

    if (!checkIfOpenPositionForType(POSITION_TYPE_SELL)) {
      openAPositionToSell(currentBid);
    }
  }
}

// Check if there is an open position for given type
bool checkIfOpenPositionForType(int positionType) {
  // Loop through all open positions
  // if strategy require to close any position before opening new one can be
  // handle here
  if (PositionSelect(_Symbol)) {
    int totalPosition = PositionsTotal();
    for (int i = totalPosition - 1; i >= 0; --i) {
      ulong ticket = PositionGetTicket(i);
      if (PositionSelectByTicket(ticket)) {
        if (PositionGetInteger(POSITION_TYPE) == positionType) {
          return true;
        }
      }
    }
  }
  return false; // No open position of the specified type found
}

void openAPositionToBuy(double askPrice) {
  // Get the minimum stop level
  long minStopLevel = SymbolInfoInteger(Symbol(), SYMBOL_TRADE_STOPS_LEVEL);

  double sl = askPrice - StopLoss * _Point;   // Stop loss price
  double tp = askPrice + TakeProfit * _Point; // Take profit price

  // Ensure SL is below ask and TP is above ask
  if (sl >= askPrice) {
    Print("stop Loss should be below ask price");
    return;
  }

  if (tp <= askPrice) {
    Print("take profit should be above ask price");
    return;
  }

  // Check validity against minimum stop level
  if ((askPrice - sl) < minStopLevel * _Point) {
    Print("Invalid Stop Loss");
    return;
  } else if ((tp - askPrice) < minStopLevel * _Point) {
    Print("Invalid Take Profit");
    return;
  }

  bool result = trade.Buy(LotSize, _Symbol, askPrice, sl, tp, "Buy Order");
  if (!result) {
    Print("Error while opening a Buy position", GetLastError());
  } else {
    printf("Success to open Buy position");
    // Check trade server return code and take action accordingly
    Print("Result Code ", trade.ResultRetcode());
  }
}

void openAPositionToSell(double bidPrice) {
  // Get the minimum stop level
  long minStopLevel = SymbolInfoInteger(Symbol(), SYMBOL_TRADE_STOPS_LEVEL);

  double sl = bidPrice + StopLoss * _Point;   // Stop loss price
  double tp = bidPrice - TakeProfit * _Point; // Take profit price

  // Ensure SL is above bid and TP is below bid
  if (sl <= bidPrice) {
    Print("Invalid Stop Loss: Must be above bid price");
    return;
  }
  if (tp >= bidPrice) {
    Print("Invalid Take Profit: Must be below bid price");
    return;
  }

  // Check validity against minimum stop level
  if ((sl - bidPrice) < minStopLevel * _Point) {
    Print("Invalid Stop Loss");
    return;
  } else if ((bidPrice - tp) < minStopLevel * _Point) {
    Print("Invalid Take Profit");
    return;
  }

  bool result = trade.Sell(LotSize, _Symbol, bidPrice, sl, tp, "Sell Order");
  if (!result) {
    Print("Error while opening a Sell position", GetLastError());
  } else {
    printf("Success to open Sell position");
    // Check trade server return code and take action accordingly
    Print("Result Code ", trade.ResultRetcode());
  }
}