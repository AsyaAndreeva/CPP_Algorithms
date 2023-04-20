#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

int main() {

    int ArraySize;
    cout << "Array size: ";
    cin >> ArraySize;

    int *Array = new int[ArraySize];
    cout << "Array: " << endl;
    for (int i = 0; i < ArraySize; i++) {
        cin >> Array[i];
    }


    int flag = false;

   do {
       flag = true;
       for (int i = 1; i < ArraySize; i++) {
            int j = i - 1;
           if (Array[i] < Array[j]) {
               swap(Array[i], Array[j]);
               flag = false;
           }
       }
   }while (flag == false);

       for (int i = 0; i < ArraySize; i++) {
           cout << Array[i]<<" ";
       }
   }