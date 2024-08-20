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

  space_joke.print_list_folders();
  print_message_contents_of_folder(travel);
  // in next print visa message shouldn't be there.
  visa.remove(travel);
  Folder copy_of_travel(travel);
  std::cout << "---------------------------------------" << std::endl;
  print_message_contents_of_folder(copy_of_travel);
}

int main() {
  create_folder_and_message();
  return 0;
}