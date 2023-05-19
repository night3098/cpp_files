#include <clocale>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");

  int i = 0;

  std::ofstream out;
  out.open("log.txt");

  srand(time(NULL));

  vector<int> data;
  cout << "Writing....." << endl;

  for (i; i < 30; i++) {
    int rnd = rand();
    data.insert(data.end(), rnd);
    cout << data[i] << endl;
    out << data[i] << endl;
  }
  return 0;
}
