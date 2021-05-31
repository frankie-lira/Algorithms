//
//  flira.cpp
//  Lab01
//
//  Created by Francisco Lira on 2/1/21.
//

#include <iostream>
using namespace std;

void insertionSort(int* InsArr, int InsSize) {
    
    int j;
    int key = 0;
    
    for (int i = 1; i < InsSize; i++) {
        key = InsArr[i];
        j = i - 1;
        
        while (j >= 0 && InsArr[j] > key) {
            InsArr[j + 1] = InsArr[j];
            j = j - 1;
        }
        InsArr[j + 1] = key;
        
        //print sequence
        for (int k = 0; k < i + 1; k++)
            cout << InsArr[k] << ";";
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    int* Sequence;
    int arraySize = 1;
    
    // This party of the code gets the size of the sequence
    cin >> arraySize;
    Sequence = new int[arraySize];
    
    // This part of the code reads the sequence
    for(int i = 0; i < arraySize; i++)
        cin >> Sequence[i];
    
    insertionSort(Sequence, arraySize);
    
    return 0;
}
