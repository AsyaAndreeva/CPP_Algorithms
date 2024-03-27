#include <iostream>

using namespace std;

void countingSort(int* arrayA, int* arrayB, int size, int k);

int main() {
    const int size = 8;
    int arrayA[size] = {2, 5, 3, 0, 2, 3, 0, 3};
    int arrayB[size];
    int k = 6; // Assuming maximum value in the array is 5
    countingSort(arrayA, arrayB, size, k);

    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arrayB[i] << " ";
    }
    cout << endl;

    return 0;
}

void countingSort(int* arrayA, int* arrayB, int size, int k){
    int arrayC[k + 1] = {0}; // Initialize all elements to 0
    for (int i = 0; i < size; ++i) {
        arrayC[arrayA[i]]++;
    }
    for (int i = 1; i <= k; ++i) {
        arrayC[i] += arrayC[i - 1];
    }
    for (int i = size - 1; i >= 0; --i) {
        arrayB[arrayC[arrayA[i]] - 1] = arrayA[i];
        arrayC[arrayA[i]]--;
    }
}
