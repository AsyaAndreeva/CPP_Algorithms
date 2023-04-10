#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

    int ArraySize;
    cout<<"What is Array size? ";
    cin>>ArraySize;

    cout<<"Array: "<<endl;
    int* Array = new int(ArraySize);

    for(int i =0; i<=ArraySize; i++){
        cin>>Array[i];
    }

    int DesiredItem;
    cout<<"Desired item: ";
    cin>>DesiredItem;

    int MatchingItemIndex=-1;
    int Counter=0;

    for (int i=0; i<=ArraySize; i++){
        if(DesiredItem==Array[i]){
            MatchingItemIndex=i;
            Counter++;
        }
    }

    if(MatchingItemIndex==-1){
        cout<<"No matching item";
    }
    else{
        cout<<"Last matching item index: "<<MatchingItemIndex<<endl;
        cout<<Counter<<" times is the item found"<<endl;
    }

    return 0;
}
