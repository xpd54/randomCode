#include <iostream>
#include <string>

int main(int argc, char **argv) {
  char *nameOfProgram = argv[0];
  char *firstInput = argv[1];
  char *secondInput = argv[2];

  std::string concatenatedString =
      std::string(firstInput) + std::string(secondInput);
  std::cout << concatenatedString << "\n";
  std::cout << argv[3] << "\n";
}