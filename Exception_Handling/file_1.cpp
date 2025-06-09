#include <iostream>
using namespace std;

double division(int a, int b) {
   if( b == 0 ) {
      throw "Division by zero condition!";
   }
   return (a/b);
}

int main () {
   int x = 50;
   int y = 0;
   double z = 0;
   char flag;
 do{
    cout<<"Enter devidend and divisor";
    cin>>x>>y;
    try {
      z = division(x, y);
      cout << z << endl;
   } catch (const char* msg) {
     cerr << msg << endl;
   }
   cout<<"Press Y to do it again and any other key to exit: ";
   cin>>flag;
 }while((flag == 'y')||(flag == 'Y'));

   return 0;
}