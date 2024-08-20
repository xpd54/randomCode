#include <string>
class StrVec {
public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(const StrVec &);
  StrVec &operator=(const StrVec &);
  ~StrVec();

  void push_back(const std::string &);
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  std::string *being() const { return elements; }
  std::string *end() const { return first_free; }

private:
  static std::allocator<std::string> alloc; // allocates the elements
  void chk_n_alloc() {
    if (size()) == capacity()) reallocate();
  }
  // utilities used by the copy constructor, assignment operator, and destructor
  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *,
                                                       const std::string *);
  void reallocate();
  std::string *elements;
  std::string *first_free;
  std::string *cap;
};