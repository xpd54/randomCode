#include <string>
class Screen {
public:
  typedef std::string::size_type pos;
  Screen() = default;
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contentens(ht * wd, c) {}
  char get() const { return contentens[cursor]; }
  inline char get(pos ht, pos wd) const;
  Screen &move(pos r, pos c);
  inline Screen &set(char);
  inline Screen &set(pos, pos, char);

private:
  pos cursor = 0;
  pos height = 0;
  pos width = 0;
  std::string contentens;
};