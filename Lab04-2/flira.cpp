//
//  flira.cpp
//  Lab04-2
//
//  Created by Francisco Lira on 2/19/21.
//

//referenced to the algorithms textbook
#include <iostream>
using namespace std;

int Partition(int arr[], int low, int high){
    int x = arr[high];
    int i = (low - 1);
    
    for(int j = low; j <= high - 1; j++){
        if(arr[j] <= x){
            i++;
            swap(arr[i], arr[j]);
            
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
    
}
int RandomPartition(int arr[],int low,int high){
    int  Random = low + rand() % (high - low);
    swap(arr[high], arr[Random]);
    return Partition(arr, low, high);
    
}
//pivot is the pivot location of quicksort
void QuickSort(int arr[], int low, int high){
    if (low < high){
        int pivot = RandomPartition(arr, low, high);
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
         
    }
    
}
int main() {
    int size;

    cin >> size;
    int arr[size];
    
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    QuickSort(arr, 0, size - 1);
    
    for(int i = 0; i < size; i++){
        cout << arr[i] << ";";
    }
    return 0;
}
