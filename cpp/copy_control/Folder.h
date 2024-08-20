#pragma once
#include "Message.h"
#include <set>
#include <string>

class Folder {
private:
  std::set<Message *> messages;

public:
  Folder(/* args */);
  ~Folder();

  void addMsg(Message *message) { messages.insert(message); }
  void remMeg(Message *message) { messages.erase(message); }
};
