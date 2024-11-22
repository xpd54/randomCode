#include <iostream>
#include <istream>
#include <ostream>

void condition_read(std::istream &istream, std::ostream &ostream) {
  int val;
  // If first error get thrown in stream.
  /*Means if we put char rather than int in first input. Cause this istream had
   * error for input it will throw error for next istream as well. And because
   * of that it will print stream error rather than taking another input for
   * next value.*/
  if (istream >> val) {
    ostream << "Second value:- " << val << std::endl;
  } else {
    ostream << "Stream had an error" << '\n';
  }
}

void clear_error_in_stream(std::istream &istream, std::istream::iostate state,
                           void (*conditon)(std::istream &, std::ostream &)) {
  // This doesn't reset if there was an error in stream
  istream.clear(istream.rdstate() & ~istream.failbit & ~istream.badbit);
  std::cout << std::cin.rdstate() << " " << std::cin.failbit << " "
            << std::cin.badbit << '\n';
  conditon(istream, std::cout);
  istream.setstate(state);
}

int main() {
  int ival;
  std::istream::iostate old_state = std::cin.rdstate();

  try {
    std::cin >> ival;
    std::cout << ival << std::endl;
  } catch (...) {
    std::cout << "Was an error" << std::endl;
  }
  std::cout << std::cin.rdstate() << " " << std::cin.failbit << " "
            << std::cin.badbit << '\n';
  clear_error_in_stream(std::cin, old_state, condition_read);
  // condition_read(std::cin, std::cout);
  return 0;
}