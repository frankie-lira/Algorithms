//  CSE 100: Algorithms
//  flira.cpp
//  Lab06
//
//  Created by Francisco Lira on 03/08/21.
//  Additional assitance on iterators from the following website: https://en.cppreference.com/w/cpp/container/list
//  Referenced to the algorithms textbook and lectures :)

#include <iostream>
#include<list>

using namespace std;

int r;

//array of lists
//Hash-Insert(T,K) book <---- book
void HashInsert(list<int>T[], int k){
    int i = 0;
    int j = k % r;
    bool BlankSpace = false; //  <-----This part was similar to lecture notes, referenced from it!
 
    if(r != 0){
    T[j].push_front(k);
        BlankSpace = true;
    }
    
    if(!BlankSpace){
      cout<<"Hash Table Overflow";
    }
}

//Hash-Search(T,k) <---- book
//HashSearch pesudo code
void HashSearch(list<int>T[], int k){
    
    list <int> :: iterator iter;
    int i = 0;
    bool found = false;
    int j = k % r;
    
   // for(int i =0; i<r;i++){ <---- lecture and book reference
    for(iter = T[j].begin(); iter != T[j].end(); ++iter){
        //advance(iter,j);
        if(*iter == k){
            cout << k << ":FOUND_AT" << j << "," << i << ";" <<endl;
            found = true;
        }
  i++;
    }
    if(!found){
        cout << k << ":NOT_FOUND;" <<endl;
    }
    
}

void HashDelete(list<int>T[],int k){
    
    list <int> :: iterator iter;
    int i = 0;
    bool deleted = false;
    int j = k % r;
    
    for(iter = T[j].begin(); iter != T[j].end(); ++iter){
        //advance(it,j);
        if(*iter == k){
            T[i].erase(iter);
            cout << k << ":DELETED;" << endl;
            deleted = true;
            break;
            //break loop to help from deleting more than one if there are repeating numbers
        }
        i++;
    }
  
    if(!deleted){
        cout << k << ":DELETE_FAILED;" << endl;
    }
}

void Print(list<int>T[]){
    
    list <int> :: iterator iter;
    
    for(int i = 0; i < r; i++){
        cout << i << ":";
        for(iter = T[i].begin(); iter != T[i].end(); ++iter){
            cout << *iter << "->";
        }
        cout << ";" <<endl;
    }
    
    
}

int main(int argc, const char * argv[]) {

    cin >> r;
    char function;
    int k;
    list<int>T[r];//<--added to avoid collisions using seperate chaining
    
    while(r != 0){
        cin >> function;
        if(function =='i'){
            cin >> k;
            HashInsert(T, k);
        }
        if(function =='s'){
            cin >> k;
            HashSearch(T, k);
        }
        if (function =='o'){
            Print(T);
        }
        if (function =='d'){
            cin >> k;
            HashDelete(T, k);
        }
        if(function =='e'){
            break;
        }
    }
    return 0;
}
