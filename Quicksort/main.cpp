#include <iostream>
#include <cstdlib> // for rand()
#include <algorithm> // for swap()

int randoMizedPartrition(int* arrayInput, int leftEnd, int rightEnd);
void randoMizedQuicksort(int* arrayInput, int leftEnd, int rightEnd);
int partrition(int* arrayInput, int leftEnd, int rightEnd);

int main() {
    int arrayInput[10] = {0, 2, 1, 3, 4, 5, 7, 8, 6, 9};
    int leftEnd = 0;
    int rightEnd = std::size(arrayInput) - 1;
    randoMizedQuicksort(arrayInput, leftEnd, rightEnd);

    // Output sorted array
    for (int i = 0; i < 10; ++i) {
        std::cout << arrayInput[i] << " ";
    }
    std::cout << std::endl;
}

int randoMizedPartrition(int* arrayInput, int leftEnd, int rightEnd){
    int randomEl = rand() % (rightEnd - leftEnd + 1) + leftEnd;;
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

void randoMizedQuicksort(int* arrayInput, int leftEnd, int rightEnd){
    if(leftEnd<rightEnd){
        int pivot = randoMizedPartrition(arrayInput, leftEnd, rightEnd);
        randoMizedQuicksort(arrayInput, leftEnd, pivot-1);
        randoMizedQuicksort(arrayInput, pivot+1, rightEnd);
    }
}
