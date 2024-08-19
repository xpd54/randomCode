#include "screen.h"

/* Screen is length X width. To reach to a point which is given by row/column we
have to go to correct row first than move accross column. So width multiply by
row will bring to correct row number and adding location of column will bring to
correct column number.*/

inline Screen &Screen::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
}

char Screen::get(pos r, pos c) const {
  pos row = r * width;
  return contentens[row + c];
}

inline Screen &Screen::set(char c) {
  contentens[cursor] = c;
  return *this;
}

inline Screen &Screen::set(pos row, pos col, char ch) {
  contentens[row * width + col] = ch;
  return *this;
}