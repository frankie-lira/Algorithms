//
//  flira.cpp
//  Lab05
//
//  Created by Francisco Lira on 2/28/21.
//

//referenced to the algorithms textbook
#include <iostream>
#include <vector>

using namespace std;

void CountingSort(vector<int> A[], int B, int k){
    vector<int>* output;
    int i;
    int C[4] = {0}; //C = Count
  
    output = new vector<int>[B];

    for (i = 0; i < B; i++) {
        C[A[i][k] % 4]++;
    }
    
    for (i = 1; i < 4; i++) {
        C[i] += C[i - 1];
    }

    for (i = B - 1; i >= 0; i--) {
        output[C[ A[i][k] % 4 ] - 1] = A[i];
        C[A[i][k] % 4 ]--;
    }
    
    for (i = 0; i < B; i++)
        A[i] = output[i];
}

void RadixSort(vector<int> A[], int d) {
    int vectorSize = 10;
    // pos = k;
    for (int k = vectorSize -1; k >= 0 ; k--) {
        CountingSort(A, d, k);
    }
}

int main(){
    int size;
    cin >> size;
    vector<int>* A = new vector<int>[size];
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 10; j++) {
            int val;
            cin >> val;
            
            A[i].push_back(val); //pushback is used
        }
    }
    //Redix Sorting, It is possible by incorporating CountingSort (used textbook to reference both algorithms)
    RadixSort(A, size);
    
    for (int i = 0; i < size; i++) {
        vector<int> :: iterator o = A[i].begin();
        while (o != A[i].end()) {
            cout << *o << ";";
            o++;
        }
        cout << endl;
    }
}
