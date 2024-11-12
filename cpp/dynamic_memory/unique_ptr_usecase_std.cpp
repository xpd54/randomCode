#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>

class Widget {
public:
  int value;
  explicit Widget(int val) : value(val) {
    std::cout << "constructor:- " << value << '\n';
  }

  virtual ~Widget() noexcept { std::cout << "destructor:- " << value << '\n'; }
};

void use_widget(const Widget *w) {
  std::cout << "using widget with ptr:- " << w->value << '\n';
}

void use_widget(const Widget &w) {
  std::cout << "using widget with ref:- " << w.value << '\n';
}

void vector_exmaple() {
  std::vector<Widget *> widgets;
  const std::size_t count = 5;
  widgets.reserve(5);
  for (std::size_t i = 0; i < count; ++i) {
    widgets.push_back(new Widget(i));
  }

  for (const auto &widget : widgets) {
    use_widget(widget);
  }

  // have to delete first before saying pop cause it's a memory leak.
  delete widgets.back();
  widgets.pop_back();

  Widget *last = widgets.back();
  /*making sure the pop_back which pop the widget have been done if not it's
   * another issue where it's getting deleted twice at end. That's undefined
   * behaviour and it turns into crash of whole process.*/
  widgets.pop_back();
  /*Need to use last after pop back or getting from back. Once it's done using
   * have delete or memory leaks*/
  std::cout << "last element was " << last->value << '\n';
  delete last;

  for (std::size_t i = 0; i < widgets.size(); ++i)
    delete widgets[i];
}

void smart_vector_example() {
  std::vector<std::unique_ptr<Widget>> widgets;
  const std::size_t count = 5;
  widgets.reserve(count);
  for (std::size_t i = 0; i < count; ++i) {
    widgets.push_back(std::make_unique<Widget>(1));
  }

  for (const auto &widget : widgets) {
    // do not change methods/function which take pointer or reference
    use_widget(*widget);
    /* access pointer accepting function*/
    // use_widget(widget.get());
  }

  widgets.pop_back();
  auto last = std::move(widgets.back());
  std::cout << "last element was " << last->value << '\n';
}

int main() {
  // vector_exmaple();
  smart_vector_example();
  return 0;
}