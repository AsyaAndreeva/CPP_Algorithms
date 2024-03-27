#include <iostream>
#include <cstdlib> // for rand()
#include <algorithm> // for swap()

int randomizedSelect(int* arrayInput, int leftEnd, int rightEnd, int smallest);
int randoMizedPartrition(int* arrayInput, int leftEnd, int rightEnd);
int partrition(int* arrayInput, int leftEnd, int rightEnd);

int main() {
    // Example usage
    int array[] = {33, 12, 0, 5, 4}; // Sample array
    int k = 4; // Find the 3rd smallest element

    int size = sizeof(array) / sizeof(array[0]);
    int result = randomizedSelect(array, 0, size - 1, k);

    std::cout << "The " << k << "-th smallest element is: " << result << std::endl;

    return 0;
}

int randomizedSelect(int* arrayInput, int leftEnd, int rightEnd, int smallest){
    if(leftEnd==rightEnd) return arrayInput[leftEnd];

    int pivot = randoMizedPartrition(arrayInput, leftEnd, rightEnd);

    int numberOfSmallerEl = pivot - leftEnd + 1;

    if(smallest == numberOfSmallerEl){
        return arrayInput[pivot];
    }else if(smallest<numberOfSmallerEl){
        return randomizedSelect(arrayInput, leftEnd, pivot-1, smallest);
    }else{
        return randomizedSelect(arrayInput, pivot+1, rightEnd, smallest-numberOfSmallerEl);
    }
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