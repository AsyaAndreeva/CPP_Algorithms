#include <iostream>
using namespace std;

void Heapify(int arrayInput[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arrayInput[left] > arrayInput[largest])
        largest = left;

    if (right < n && arrayInput[right] > arrayInput[largest])
        largest = right;

    if (largest != i) {
        swap(arrayInput[i], arrayInput[largest]);
        Heapify(arrayInput, n, largest);
    }
}

void BuildMaxHeap(int arrayInput[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(arrayInput, n, i);
    }
}

void Heapsort(int arrayInput[], int n) {
    BuildMaxHeap(arrayInput, n);
    for (int i = n - 1; i >= 0; i--) {
        swap(arrayInput[0], arrayInput[i]);
        Heapify(arrayInput, i, 0);
    }
}

int main() {
    int arr[14] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    Heapsort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
