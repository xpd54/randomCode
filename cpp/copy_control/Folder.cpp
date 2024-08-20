#include "Folder.h"
#include <iostream>
Folder::Folder(const Folder &folder)
    : folder_name(folder.folder_name), messages(folder.messages) {}
Folder &Folder::operator=(const Folder &rhs_folder) {
  messages.clear();
  folder_name = rhs_folder.folder_name;
  messages = rhs_folder.messages;
  return *this;
}

Folder::~Folder() { messages.clear(); }

void print_message_contents_of_folder(Folder &folder) {
  std::vector<std::string> list = folder.get_list_message_contents();
  for (auto &value : list)
    std::cout << value << std::endl;
}