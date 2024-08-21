#include "main.h"
#include "Folder.h"
#include "Message.h"
#include <iostream>
#include <set>
#include <string>
class Holding {
private:
  std::set<std::string> packet;
  std::string name;

public:
  Holding(std::string _name_) : name(_name_) {}
  void save(const std::string &value) { packet.insert(value); }

  void print() {
    std::cout << name << " ";
    for (auto &value : packet)
      std::cout << value << " ";
    std::cout << std::endl;
  }
};

void add_and_print_holding() {
  Holding holding("Hello");
  const std::string message("World");
  const std::string address("Hong Kong");
  holding.save(message);
  holding.save(address);
  holding.print();
}

void seperator() {
  std::cout << "---------------------------------------" << std::endl;
}

void create_folder_and_message() {
  Folder travel("Travel");
  Message ticket("Hello your ticket is confrimed to NYC pelase find pdf.");
  Message visa("Visa to USA is confirmed please submit your passport to "
               "collect thanks.");
  Folder meme("Meme");
  Message dm_joke("I am traveling back in time.");
  Message space_joke(
      "What happen when you travel to space and someone don't enter.");

  ticket.save(travel);
  visa.save(travel);

  meme.addMsg(&dm_joke);
  space_joke.save(meme);

  dm_joke.save(travel);
  space_joke.save(travel);

  // space_joke.print_list_folders();
  // print_message_contents_of_folder(travel);
  // in next print visa message shouldn't be there.
  visa.remove(travel);
  Folder copy_of_travel(travel);

  seperator();
  // print_message_contents_of_folder(copy_of_travel);

  seperator();

  // copy constructor
  Message copy_ticket(ticket);
  // copy_ticket.print_list_folders();

  seperator();
  // copy assignment for message
  copy_ticket = space_joke;
  // copy_ticket.print_list_folders();
}

Message return_rvalue_message() {
  Message original("Hello World, We gonna move");
  return original;
}

/* Using rvalue vs lvalue can show difference for how copy assignment, copy
 * constructor, move assignment and move constructor is working around here.to
 * get rvalue we can use std::move or if a function is returning message that
 * returns rvalue
 */
void moving_message() {
  Message empty_message;
  Message another("hello");
  Message originalMessage(std::move(another));
  // originalMessage.print_message_contents();
  empty_message = return_rvalue_message();
  // empty_message.print_message_contents();
}

void print_rvalue(std::string &&value) { std::cout << value << std::endl; }

void print_pointer() {
  int a = 43;
  int *ap = &a;
  int *bp = std::move(ap);

  std::cout << &ap << " " << &bp << std::endl;
  std::cout << ap << " " << bp << std::endl;
  std::cout << *ap << " " << *bp << " " << &a << std::endl;

}
int main() {
  print_pointer();
  // moving_message();
  // std::string a("hello");
  // print_rvalue(std::move(a));
  // std::cout << a << std::endl;
  // create_folder_and_message();
  return 0;
}