#pragma once
#include "Message.h"
#include <iostream>
#include <set>
#include <string>
#include <vector>
class Folder {

private:
  std::set<Message *> messages;
  std::string folder_name;

public:
  Folder(const std::string &name = " ") : folder_name(name) {}
  Folder(const Folder &);
  Folder &operator=(const Folder &);
  ~Folder();

  std::string &get_folder_name() { return folder_name; }
  std::vector<std::string> get_list_message_contents() {
    std::vector<std::string> list;
    for (auto &value : messages)
      list.push_back(value->contents);
    return list;
  }
  void addMsg(Message *message) { messages.insert(message); }
  void remMeg(Message *message) { messages.erase(message); }
};

void print_message_contents_of_folder(Folder &);