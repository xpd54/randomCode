#include "Folder.h"

Folder::Folder(const Folder &folder)
    : folder_name(folder.folder_name), messages(folder.messages) {}
Folder &Folder::operator=(const Folder &rhs_folder) {
  messages.clear();
  folder_name = rhs_folder.folder_name;
  messages = rhs_folder.messages;
  return *this;
}

Folder::~Folder() { messages.clear(); }