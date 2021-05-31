//  CSE 100: Algorithms
//  flira.cpp
//  Lab09
//
//  Created by Francisco Lira on 04/04/21.
//lossless data compression algorithm

#include<iostream>
#include<deque>
#include<map>
#include<queue>
#include<string>

using namespace std;

map <char, string> C;

struct  Node {
    char letr;
    double frequency;
    Node* left;
    Node* right;
   
    
};
struct comparenodes {
    bool operator()(Node* left, Node* right){
        return (left -> frequency > right -> frequency);
    }
};

priority_queue <Node *, deque <Node *>, comparenodes> Q;
//priority queue was instructed by the book
//priority_queue <Type, vector<Type>, ComparisonType > min_heap;

Node* Getnew(char letr, double frequency){
    Node* newnode = new Node();
    newnode -> frequency = frequency;
    newnode -> letr = letr;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
    
}
Node* empty(){
    Node* temporary= new Node();
    temporary -> left = NULL;
    temporary -> right = NULL;
    temporary -> letr = NULL;
    temporary -> frequency = NULL;
    return temporary;
}

static void encoding(Node *Q, string encode, int i) {
    char letrs[]={'A','B','C','D','E','F'};
    
    if (Q == NULL) {
        return;
    }
    
    if (Q -> letr == letrs[i]) {
        C.insert(make_pair (letrs[i], encode));
    }
    
    if (Q -> letr != letrs[i]){
        encoding(Q -> left, encode + "0", i);
        //adds on to the string
        encoding(Q -> right, encode + "1", i);
    }
};

void HuffmanTree(){
    Node *d = empty();
    //establish new nodes
    Node *e = empty();
    //establish new nodes
    Node *f = empty();
    //establish new nodes
    
    for(int m = 6; m != 1; m--){
        d = Q.top();
        //d = extractmin(Q)
        //gets new min
        Q.pop();
        //min element gets removed
        e = Q.top();
        Q.pop();
        f = Getnew(' ', (d -> frequency + e -> frequency));
        // gets our addition of both nodes being added based on the frequency
        f -> left = d;
        //makes left child off of the x min
        f -> right = e;
        //makes right child off of the y min
        Q.push(f);
    }
}


int main(){
    
    double frequency;
    int d = 0;
    
    while (d != 6){
      
        cin >> frequency;
        if (d == 0){

            Q.push(Getnew('A', frequency));
        }
        if (d == 1){
            Q.push(Getnew('B', frequency));

        }
        if (d == 2){
            Q.push(Getnew('C', frequency));

        }
        if (d == 3){
            Q.push(Getnew('D', frequency));

        }
        if (d == 4){
            Q.push(Getnew('E', frequency));

        }
        
        if (d == 5){
            Q.push(Getnew('F', frequency));

        }
     
        d++;
    }
    HuffmanTree();
    
    for (int i = 0; i < 6; i++) {
                encoding(Q.top(), "", i);
        
    }
    //This statemnet is going to be printing out the encoded letters

     map<char, string> :: iterator iter = C.begin();
    
        while(iter != C.end()){
        cout << iter -> first << ":" << iter -> second << endl;
                    iter++;
        
         }
}
