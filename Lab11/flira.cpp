//  CSE 100: Algorithms
//  flira.cpp
//  Lab11
//  Created by Francisco Lira on 04/20/21.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int key[1000];
int parent[1000];//parent array
typedef pair<int, int> IntPair;//Int pair
bool Visit[1000]; //This will show what has been visited in the Minimum Spanning Tree
vector<IntPair> adjacent[1000];



//MST-Prism pseudo code from the algorithms textbook!
void MSTPrims(int j){
    // we have to create a priority queue that will hopefully hold the respective vertices in the same place!
    priority_queue< IntPair, vector<IntPair>, greater<IntPair> > F;
    F.push(pair<int,int>(0,0));
    
    for(int i = 0; i < j; i++){
        key[i] = 999999; //infinty 999999999
        parent[i] = 0; //parent
    }
    
    do{
        int x = F.top().second;
        F.pop();
        Visit[x] = true;
      
        for(int i = 0; i < adjacent[x].size(); i++){
            int o = adjacent[x][i].first;
            int p = adjacent[x][i].second;
            
            if(!Visit[o] && key[o] > p){
                key[o] = adjacent[x][i].second;
                F.push(pair <int,int> (p,o));
                parent[o] = x;
            }
        }
    }
    
    while(!F.empty());{
        for(int i = 1; i < j; i++){
            cout << parent[i] << endl;
        }
    }
}

int main(){
    int a, b, c, d, e;
    
    cin >> a;
    cin >> b;

    //this part of the code creates the graph
    for(int i = 0; i < b; i++){
        cin >> c >> d >> e;
        adjacent[c].push_back(make_pair(d, e));
        adjacent[d].push_back(make_pair(c, e));
    }
    //calls out Minimum Spanning Tree Code (MSTPrims)
    MSTPrims(a);
    return 0;
}
