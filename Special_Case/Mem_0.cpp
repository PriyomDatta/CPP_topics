#include <iostream>
using namespace std;

int main () {
    double* pvalue  = NULL; // Pointer initialized with null
    pvalue  = new double;   // Request memory for the variable 
    *pvalue = 29494.99;     // Store value at allocated address
    cout << "Value of pvalue : " << *pvalue << endl;
    cout << "Memory adress is : "<< pvalue << endl;
    cout << "Memory adress is : "<< &pvalue << endl;
    delete pvalue;         // free up the memory.

    double* pvalue1  = NULL;
    pvalue1  = new double;   // Request memory for the variable
    *pvalue1 = 29494.99;     // Store value at allocated address
    cout << "Value of pvalue : " << *pvalue1 << endl;
    cout << "Memory adress is : "<< pvalue1 << endl;
    cout << "Memory adress is : "<< &pvalue1 << endl;
    delete pvalue1;         // free up the memory.
   return 0;
}