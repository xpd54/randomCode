#include <iostream>
class PacketData {

public:
  PacketData() : constructor(0) {
    packet = nullptr;
    constructor++;
  }
  int constructor;
  int *packet;
  void printPacket() { std::cout << packet << " " << constructor << "\n"; }
};

int main() {
  PacketData data;
  if (data.packet == nullptr)
    data.printPacket();
  else
    std::cout << "boo"
              << "\n";
  return 0;
}