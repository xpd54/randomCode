#pragma once
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
  unique_ptr() noexcept;
  explicit unique_ptr(T *ptr) noexcept;
  unique_ptr(const unique_ptr &) = delete;
  unique_ptr &operator=(const unique_ptr &) = delete;
  unique_ptr(unique_ptr &&other);
  unique_ptr &operator=(unique_ptr &&other) noexcept;
  explicit operator bool() const noexcept;
  T *get() const noexcept;
  T *operator->() const noexcept;
  T &operator*() const noexcept;
  T *release() noexcept;
  void reset(T *ptr = nullptr) noexcept;
  ~unique_ptr();

private:
  T *m_ptr;
};

template <typename T, typename... Args>
unique_ptr<T> make_unique(Args &&...args);