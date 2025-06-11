#include <iostream>
using namespace std;

int A = __LINE__;
const char* B = __FILE__;
const char* C = __DATE__;
const char* D = __TIME__;

int main () {
   cout << "Value of __LINE__ : " << A << endl;
   cout << "Value of __FILE__ : " << B << endl;
   cout << "Value of __DATE__ : " << C << endl;
   cout << "Value of __TIME__ : " << D << endl;

   return 0;
}