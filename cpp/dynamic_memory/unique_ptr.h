#pragma once
#include <utility>
template <typename T> class unique_ptr {
  /*1. Default constructor []
    2. Constructor which takes new pointer []
    3. copy constructor deleted []
    4. copy assignment deleted []
    5. Move constructor []
    6. Move assignment []
    7. Boolean operator overload []
    8. -> operator overload returns pointer []
    9. * operator which dereference underlying ptr []
    10. get() method which returns underlying ptr []
    12. release() method which from one to another release underlying ptr and
    release ownership []
    13. reset one to nullptr or reset with given value; []
    14. destructor
    14. make_unique() takes new ptr and return unique_ptr it's not a method*/
public:
  unique_ptr() noexcept : m_ptr(nullptr) {}

  explicit unique_ptr(T *ptr) noexcept : m_ptr(ptr) {}

  unique_ptr(const unique_ptr &) = delete;

  unique_ptr &operator=(const unique_ptr &) = delete;

  unique_ptr(unique_ptr &&other) : m_ptr(other.release()) {}

  unique_ptr &operator=(unique_ptr &&other) noexcept {
    if (this != &other) {
      reset(other.release());
    }
    return *this;
  }

  explicit operator bool() const noexcept { return static_cast<bool>(m_ptr); }

  T *get() const noexcept { return m_ptr; }

  T *operator->() const noexcept { return m_ptr; }

  T &operator*() const noexcept { return *m_ptr; }

  T *release() noexcept {
    return std::exchange(m_ptr, nullptr); // c++14
  }

  void reset(T *ptr = nullptr) noexcept {
    T *old_ptr = std::exchange(m_ptr, ptr);
    if (old_ptr) {
      delete old_ptr;
    }
  };

  ~unique_ptr() noexcept {
    if (m_ptr)
      delete m_ptr;
  }

private:
  T *m_ptr;
};

template <typename T, typename... Args>
unique_ptr<T> make_unique(Args &&...args) {
  return unique_ptr<T>(new T(std::forward<Args>(args)...));
}
