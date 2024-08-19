#include "Folder.h"
#include <set>
#include <string>
class Message {
  friend class Folder;

private:
  std::string contents;       // actual message text
  std::set<Folder *> folders; // set of Folders which holds this message
  /*this will get used by copy constructor where if we copy a message it's
   * folder should get added to new message*/
  /*add this message to the folder that point to the parameter*/
  void add_to_Folders(const Message &);
  // remove this message from every Folder in folders
  void remove_from_Folders();

public:
  // folders is implicitly initialized to the empty set
  explicit Message(const std::string &str = " ") : contents(str) {}

  // copy control to manage pointers to the Message
  Message(const Message &);            // copy constructor
  Message &operator=(const Message &); // copy assignment
  ~Message();

  // add/remove this Message from the specified Folder's set of message
  void save(Folder &);
  void remove(Folder &);
};
