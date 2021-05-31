//
//  flira.cpp
//  Lab04-1
//
//  Created by Francisco Lira on 2/19/21.
//

//referenced to the algorithms textbook
#include <iostream>

using namespace std;

void swap(int arr[], int x, int y){
    
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}
//"MaxHeapify"
void Heapify(int arr[], int n, int i){
    int max = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    
    if(left < n && arr[left] > arr[i]){
        max = left;
    }
    if(right < n && arr[right] > arr[max]){
        max = right;
    }
    if(max != i){
        swap(arr, i, max);
        Heapify(arr, n, max);
    }
}
void BuildMaxHeap(int arr[], int n){
    for(int i = (n / 2) - 1; i >= 0; i--){
        Heapify(arr, n, i);
    }
}

void HeapSort(int arr[], int n){
    BuildMaxHeap(arr, n);
    for(int i = n - 1; i >= 0; i--){
        swap(arr, i, 0);
        Heapify(arr, i , 0);
    }
}
int main(){
    int size;
    cin >> size;
    
    int arr[size];
   
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    HeapSort(arr, size);
    for(int j = 0; j < size; j++){
        cout << arr[j] << ";";
        
    }
}
