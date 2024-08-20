#pragma once
#include "Message.h"
#include <set>
#include <string>

class Folder {
private:
  std::set<Message *> messages;
  std::string folder_name;

public:
  Folder(const std::string &name = " ") : folder_name(name) {}
  Folder(const Folder &);
  Folder &operator=(const Folder &);
  ~Folder();

  void addMsg(Message *message) { messages.insert(message); }
  void remMeg(Message *message) { messages.erase(message); }
};
