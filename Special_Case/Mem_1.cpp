#include <iostream>
#include <cstdlib>

using namespace std;

void checkStackAndHeap() {
    // Stack variables
    int stackVar1 = 10;
    int stackVar2 = 20;

    // Heap variables
    int* heapVar1 = (int*)malloc(sizeof(int));
    int* heapVar2 = (int*)malloc(sizeof(int));

    // Assign values to heap memory
    *heapVar1 = 100;
    *heapVar2 = 200;

    // Print addresses and values
    cout << "Stack variable 1 address: " << &stackVar1 << ", value: " << stackVar1 << endl;
    cout << "Stack variable 2 address: " << &stackVar2 << ", value: " << stackVar2 << endl;

    cout << "Heap variable 1 address: " << heapVar1 << ", value: " << *heapVar1 << endl;
    cout << "Heap variable 2 address: " << heapVar2 << ", value: " << *heapVar2 << endl;

    // Free heap memory
    free(heapVar1);
    free(heapVar2);
}

int main() {
    checkStackAndHeap();
    return 0;
}
