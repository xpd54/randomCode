#include "Message.h"
#include "Folder.h"
#include <iostream>
Message::Message(const Message &msg)
    : contents(msg.contents), folders(msg.folders) {
  std::cout << "copy constructor"
            << "\n";
  add_to_Folders(msg); // add this message to the Folders that points to msg
}

Message::Message(Message &&msg) : contents(std::move(msg.contents)) {
  std::cout << "move constructor"
            << "\n";
  move_Folders(&msg);
}

Message &Message::operator=(const Message &rhs_msg) {
  std::cout << "copy assignment"
            << "\n";
  /*As we are making copy from right to left left should get clean up that's
   * exactly what remove_from_folders does it remove all the reference where
   * this was added in folders*/
  remove_from_Folders();       // remove this from existing folder;
  contents = rhs_msg.contents; // copy the contents of rhs_msg (string copy
                               // assignment will get called)
  folders = rhs_msg.folders; // copy the std::set<Folder *> (set copy assignment
                             // will get called)
  add_to_Folders(
      rhs_msg); // add this message to the folders where all rhs_msg was added
  return *this;
}

// Message &&rhs_msg is r value reference. means &rhs_msg make total sense
Message &Message::operator=(Message &&rhs_msg) {
  std::cout << "move is assignment"
            << "\n";
  // protect from self move
  if (this != &rhs_msg) {
    remove_from_Folders();
    // careful not to move the folder first as after that contents get deleted.
    contents = std::move(rhs_msg.contents);
    move_Folders(&rhs_msg);
  }
  return *this;
}

Message::~Message() { remove_from_Folders(); }

void Message::save(Folder &f) {
  folders.insert(&f);
  f.addMsg(this);
}

void Message::remove(Folder &f) {
  folders.erase(&f);
  f.remMeg(this);
}

void Message::add_to_Folders(const Message &message) {

  for (auto &folder : message.folders)
    folder->addMsg(this);
}

void Message::remove_from_Folders() {
  for (auto &folder : this->folders)
    folder->remMeg(this);
  folders.clear(); // no folders points to this message
}

void Message::print_list_folders() {
  for (auto &value : folders)
    std::cout << value->get_folder_name() << std::endl;
}

void Message::print_message_contents() { std::cout << contents << std::endl; }

void Message::move_Folders(Message *m) {
  folders = std::move(m->folders);
  for (auto f : folders) {
    f->remMeg(m);
    f->addMsg(this);
  }
  m->folders.clear();
}