/*	������� � �������	*/

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main() {
  setlocale(LC_ALL, "Russian"); // �����������

  int i = 0;
  int k = 0;
  int z = 0;

  std::string days[7] = {"��", "��", "��", "��", "��", "��", "��"};
  short nums[6] = {19, 26, 35, 48, 51, 67};

  int counts[5] = {};

  // for(i; i < sizeof(days); i++) {
  //	std::cout << days[i] << std::endl;
  // }
  /*
  for(i; i< 6; i++) {
          if(nums[i] % 2 == 0) {
                  std::cout << nums[i] << " - ������ �����" << std::endl;
          }
          else {
                  std::cout << nums[i] << " - �� ������ �����" << std::endl;
          }
  }
  */

  int sum = 0;

  for (k; k < 6; k++) {
    sum = sum + nums[k];
  }

  std::cout << "����� = " << sum << std::endl;

  int max = nums[0];
  for (z; z < sizeof(nums); z++) {
    if (nums[z] > max) {
      max = nums[z];
    }
  }

  std::cout << "������������ �������� = " << max << std::endl;

  int min = nums[0];
  for (z; z < sizeof(nums); z++) {
    if (nums[z] < min) {
      min = nums[z];
    }
  }

  std::cout << "����������� �������� = " << min << std::endl;

  // �������
  /*
  std::vector<int> vec(4);

  vec_r[0] = 5;
  vec_r[1] = 2;
  vec_r[2] = 94;
  vec_r[3] = 321;

  int x = 0;

  for(x;x<vec_r.size();x++){
          std::cout
  }
  */

  // std::vector<int> vec;
  // vec.insert(vec.end(), 2);
  //	vec.insert(vec.end(), 36);
  //	vec.insert(vec.end(), 12);

  std::vector<std::string> names1;
  std::cout << "������� �����: " << std::endl;
  while (1) {
    std::string str;
    std::cin >> str;
    names1.insert(names1.end(), str);
    if (str == "e")
      break;
  }

  std::vector<std::string> names2;
  names2 = names1;
  std::cout << names2 << std::endl;

  return 0;
}
