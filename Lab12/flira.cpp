//  CSE 100: Algorithms
//  flira.cpp
//  Lab12
//  Created by Francisco Lira on 04/25/21.
//  Referenced to the Bellman-Ford Algorithm in the Introduction to Algorithms Textbook page 651

#include <iostream>

using namespace std;

void PrintFunction(int *e, int MW){
    cout << "TRUE" << endl;
    for(int i = 0; i < MW; i++){
        if(e[i] == INT_MAX)
            cout << "INFINITY" <<endl;
        
        if(e[i] < INT_MAX)
            cout << e[i] <<endl;
    }
}

void Relax(int **Graph, int *e, int MW, int MF) {
    int m;
    int n;
    
    for(m = 1; m < MW; m++) {
        for(n = 0; n < MF; n++) {
            int q = Graph[2][n];
            int p = Graph[1][n];
            int o = Graph[0][n];
            
            if(e[o] != INT_MAX) {
                if(e[p] > e[o] + q) {
                    e[p] = e[o] + q;
                    
                }
            }
        }
    }
}

void InitializeSingleSource(int *e, int MW){
    for(int i = 0; i < MW; i++) {
        e[i] = INT_MAX;
    }
    e[0] = 0;
}

void BellmanFord(int ** Graph, int MW, int MF) {
    int cond = 1;
    bool reach = true;
    int j;
    int i;
    int e[MW];
   
    InitializeSingleSource(e, MW);
    Relax(Graph, e, MW, MF);
    
    for(j = 0; j < MF; j++){
        int p = Graph[1][j];
        int q = Graph[2][j];
        int o = Graph[0][j];
        
        if(e[o] != INT_MAX){
            if(e[Graph[1][j]] > e[Graph[0][j]] + Graph[2][j])
                cond = 2;
        }
    }
    switch(cond){
        case 1:
            PrintFunction(e, MW);
            break;
        
        case 2:
            cout << "FALSE" << endl;
            break;
        
        default:
            NULL;
    }
}

int main() {
    
    int o = 0;
    int p = 0;
    int q = 0;
    int j;
    int i;
    int MW = 0;
    int MF = 0;
    int **Graph;
    Graph = new int *[3];
    
    cin >> MW;
    cin >> MF;

    for(i = 0; i < MW; i++) {
        Graph[i] = new int[MF];
    }
    
    for(i = 0; i < MF; i++) {

        cin >> o >> p >> q;
        Graph[0][i] = o;
        
        Graph[1][i] = p;
        
        Graph[2][i] = q;
    }
    
    BellmanFord(Graph, MW, MF);
    
    return 0;
    
}
