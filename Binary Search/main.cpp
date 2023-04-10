#include <iostream>

using std::cin;
using std::cout;
using std::endl;


int main() {

    int ArraySize = 6;
    int Array[6] = {1, 2, 3, 4, 5, 6};

    int DesiredItem = 5;

    int left = 0;
    int right = ArraySize - 1;


    while (left <= right) {

        int MiddleIndex = (left + right) / 2;
        int MiddleItem = Array[MiddleIndex];

        if (MiddleItem == DesiredItem) {
            cout << "Desired item index: "<<MiddleIndex;
            break;
        }

        if (MiddleItem < DesiredItem) {
            left = MiddleIndex;
        }

        if (MiddleItem > DesiredItem) {
            right = MiddleIndex;
        }
    }


    return 0;
}
