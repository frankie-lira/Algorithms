//
//  flira.cpp
//  Lab03
//
//  Created by Francisco Lira on 2/12/21.
//

//referenced to the algorithms textbook
#include <iostream>
#define intLim 2147483646 //this references to infinity in the textbook
using namespace std;

int FindMaxCrossingSubArray(int* A, int low, int mid, int high) {
    int RightSum = -1 * intLim; //(-infinity)
    int LeftSum = -1 * intLim; //(-infinity)
    int sum = 0;
    
    for(int i = mid; i >= low; i--) {
        sum = sum + A[i];
        if(sum > LeftSum) {
            LeftSum = sum;
        }
    }
    sum = 0;
    for(int j = mid + 1; j <= high; j++) {
        sum = sum + A[j];
        if(sum > RightSum) {
            RightSum = sum;
        }
    }
    return LeftSum + RightSum; //(max-left,max-right,leftsum + right-sum)
}

int FindMaxSubArray(int* A, int low, int high) {
    if (high == low){
        return A[low];
    }
    int mid = (low + high)/2;
    int CrossSum = FindMaxCrossingSubArray(A, low, mid, high);//(crosslow, crosshigh, crosssum)
    int LeftSum = FindMaxSubArray(A, low, mid);//(leftlow, lefthigh, leftsum)
    int RightSum = FindMaxSubArray(A, mid + 1, high);//(rightlow, righthigh, rightsum)
    
    if(LeftSum >= RightSum && LeftSum >= CrossSum)
        return LeftSum;//(leftlow, lefthigh, leftsum)
    
    else if(RightSum >= LeftSum && RightSum >= CrossSum)
        return RightSum; //(rightlow, righthigh, rightsum)
    
    else
        return CrossSum; //(crosslow, crosshigh, crosssum)
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
    
    cout << FindMaxSubArray(Sequence, 0, arraySize - 1);
    return 0;}
