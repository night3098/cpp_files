#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main() {
  setlocale(LC_ALL, "Russian");

  int i = 0;

  std::vector<std::string> data;
  std::cout << "Please enter a names: " << std::endl;
  while (1) {
    std::string str;
    std::cin >> str;
    data.insert(data.end(), str);
    if (str == "exit") {
      for (i; i < sizeof(data); i++) {
        std::cout << "LOG[" << i << "]: " << std::endl;
        std::cout << data[i] << std::endl;
      }
      break;
    }
  }

  return 0;
}