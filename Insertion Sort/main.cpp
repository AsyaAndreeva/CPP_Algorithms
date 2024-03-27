#include <iostream>
using namespace std;

void insertionSort(int* arrayInput, int size);

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before sorting: ";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    insertionSort(arr, size);

    cout << "Array after sorting: ";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

void insertionSort(int* arrayInput, int size){
    for(int j = 1; j < size; j++){
        int key = arrayInput[j];
        int i = j - 1;
        while(i >= 0 && arrayInput[i] > key){
            arrayInput[i + 1] = arrayInput[i];
            i--;
        }
        arrayInput[i + 1] = key;
    }
}
