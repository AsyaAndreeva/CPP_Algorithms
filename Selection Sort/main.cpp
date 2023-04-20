#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

int main() {

    int ArraySize;
    cout << "Array size: ";
    cin >> ArraySize;

    int *Array = new int(ArraySize);
    cout << "Array: " << endl;
    for (int i = 0; i < ArraySize; i++) {
        cin >> Array[i];
    }

    for (int i = 0; i < ArraySize; i++) {
        for (int j = i + 1; j < ArraySize; j++) {
            if (Array[i] > Array[j]) {
                swap(Array[i], Array[j]);
            }
        }
    }

    for (int i = 0; i < ArraySize; i++) {
        cout << Array[i];
    }

    return 0;
}