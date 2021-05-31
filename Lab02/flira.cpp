//
//  flira.cpp
//  Lab02
//
//  Created by Francisco Lira on 2/6/21.
//

#include <iostream>
#define intLim 2147483647 //in the textbook this referneces to infinity
using namespace std;
//p low
//q = mid
//r = high

void Merge(int* Arr, int p, int q, int r) {
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1+1];
    int R[n2+1];
    
    for(i = 0; i < n1; i++)
        L[i] = Arr[p + i];
    
    for(j = 0; j < n2; j++)
        R[j] = Arr[q + 1 + j];
    
    L[n1] = intLim;
    R[n2] = intLim;
    
    i = 0;
    j = 0;
    
    for(k = p; k <= r; k++) {
        if(L[i] <= R[j])
            Arr[k] = L[i++];
        else
            Arr[k] = R[j++];
    }
}

void MergeSort(int *Arr, int p, int r) {
    int q;
    
    if (p < r) {
        q = (p + r) / 2;
        MergeSort(Arr, p, q);
        MergeSort(Arr, q + 1, r);
        Merge(Arr, p, q, r);
    }
}
int main(int argc, const char * argv[]) {
    int* Sequence;
    int arraySize = 1;
    
    // This part of the code gets the size of the sequence
    cin >> arraySize;
    Sequence = new int[arraySize];
    
    // This part of the code reads the sequence
    for(int i = 0; i < arraySize; i++)
        cin >> Sequence[i];
    
    MergeSort(Sequence, 0, arraySize - 1);
    
    for(int i = 0; i < arraySize; i++)
        cout << Sequence[i] << ";";
    
    return 0;
}
