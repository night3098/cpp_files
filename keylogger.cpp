#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int main(int argc, char  ** agrv){
     using namepace std; /*Easier*/
  
     char std::vector input_STRUCT = ["S", "T", "O"];
     char std::vector input_STRUCT_1 = ["P", " "];
     char std::vector input_STRUCT_2 = ["L", "O", "O", "K", "I", "N", "G"];
     char std::vector input_STRUCT_3 = [" ", "F", "O", "R"];
     char std::vector input_STRUCT_4 = ["M", "A", "L", "W"];
     char std::vector input_STRUCT_5 = ["A", "R", "E"];


     ostream os("C:\users\keylogger.txt");

     int i;

     for( i = 0; i <=2; i++){
          os << input_STRUCT[i];
          
          for(;i <= 1000000 ;i++){
          }
     }

     for(i=0; i<=1;i++){
          os << input_STRING_1[i];

          for(;i <= 1000000 ;i++){
          }
     }


     for(i=0; i<=6;i++){
          os << input_STRING_2[i];

          for(;i <= 1000000 ;i++){
          }


     for(i=0; i<=3;i++){
          os << input_STRING_3[i];

          for(;i <= 1000000 ;i++){
          }
     }


     for(i=0; i<=3;i++){
          os << input_STRING_4[i];

          for(;i <= 1000000 ;i++){
          }
     }


     for(i=0; i<=2;i++){
          os << input_STRING_5[i];

          for(;i <= 1000000 ;i++){
          }
     }

os.close();

istream is("D:\keylogger.txt");

cout << is;


     return 0;
}
