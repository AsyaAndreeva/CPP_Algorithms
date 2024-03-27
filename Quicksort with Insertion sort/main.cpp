#include <iostream>
#include <cstdlib> // for rand()
#include <algorithm> // for swap()

void randoMizedQuicksortWithInsertionSort(int* arrayInput, int leftEnd, int rightEnd, int threshold);
void insertionSort(int* arrayInput, int size);

int randoMizedPartrition(int* arrayInput, int leftEnd, int rightEnd);
int partrition(int* arrayInput, int leftEnd, int rightEnd);

int main() {
    int arrayInput[10] = {0, 2, 1, 3, 4, 5, 7, 8, 6, 9};
    int leftEnd = 0;
    int rightEnd = std::size(arrayInput) - 1;
    int threshold = 5;
    randoMizedQuicksortWithInsertionSort(arrayInput, leftEnd, rightEnd, threshold);

    // Output sorted array
    for (int i = 0; i < 10; ++i) {
        std::cout << arrayInput[i] << " ";
    }
    std::cout << std::endl;
}

void randoMizedQuicksortWithInsertionSort(int* arrayInput, int leftEnd, int rightEnd, int threshold){
    if(leftEnd<rightEnd){
        if(rightEnd - leftEnd + 1<=threshold){
            insertionSort(arrayInput + leftEnd, rightEnd - leftEnd + 1);
        }else {
            int pivot = randoMizedPartrition(arrayInput, leftEnd, rightEnd);
            randoMizedQuicksortWithInsertionSort(arrayInput, leftEnd, pivot - 1, threshold);
            randoMizedQuicksortWithInsertionSort(arrayInput, pivot + 1, rightEnd, threshold);
        }
    }
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

int randoMizedPartrition(int* arrayInput, int leftEnd, int rightEnd){
    int randomEl = rand() % (rightEnd - leftEnd) + leftEnd;;
    std::swap(arrayInput[rightEnd], arrayInput[randomEl]);
    return partrition(arrayInput, leftEnd, rightEnd);
}

int partrition(int* arrayInput, int leftEnd, int rightEnd){
    int pivot = arrayInput[rightEnd];
    int i = leftEnd - 1;
    for(int j = leftEnd; j <= rightEnd - 1; j++){
        if(arrayInput[j]<=pivot){
            i++;
            std::swap(arrayInput[i], arrayInput[j]);
        }
    }
    std::swap(arrayInput[i+1], arrayInput[rightEnd]);
    return i+1;
}