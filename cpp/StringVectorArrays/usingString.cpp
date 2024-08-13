#include <iostream>
#include <string>
void default_string() {
  std::string s1;
  std::string s2 = s1;
  std::string s3 = "hiya";
  std::string s4(10, 'c');
  std::cout << s4 << "\n";
}

void direct_copy_initialization() {
  std::string s5 = "hiya"; // copy initialization
  std::string s6("hiya");  // direct initialization
  std::string s7(20, 'c'); // direct initialization s7
}

void reading_writing_string() {
  // std::string s;
  // std::cin >> s; // read a whitespace-seperated string into s
  // std::cout << s << std::endl;
  std::string line;
  getline(std::cin, line);
  std::cout << line << " is it emppty " << line.empty() << " Size of String is "
            << line.size() << " first char is " << line[0] << std::endl;
}

void read_till_end() {
  std::string word;
  while (std::cin >> word) {
    std::cout << word << std::endl;
  }
}

void read_with_getline() {
  std::string line;
  while (getline(std::cin, line)) {
    std::cout << line << std::endl;
  }
}

void comparing_sting() {
  std::string str = "Hello";
  std::string phrase = "Hello World";
  std::string slang = "Hiya";
  std::cout << (str > phrase) << (phrase > slang) << (slang > str) << "\n";
}

void adding_string() {
  std::string s1 = "Hello, ";
  std::string s2 = "World\n";
  std::string s3 = s1 + s2;
  std::cout << s3 << "\n";
  std::cout << (s1 += s2) << "\n";
}

void adding_string_and_literal() {
  std::string s1("Hello");
  std::string s2;
  std::cout << "Hello " + s1 + "world " + "s1"
            << "\n";
}

int main() {
  adding_string_and_literal();
  return 0;
}