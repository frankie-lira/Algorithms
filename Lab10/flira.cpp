//  CSE 100: Algorithms
//  flira.cpp
//  Lab10
//  Created by Francisco Lira on 04/10/21.
//
//

#include <iostream>
#include <vector>

using namespace std;

static int MaxInt = INT8_MAX;
int tiempo = 0;

vector<int> vect;
vector<int> FinishTiempo;
vector<int> TiempoFinishTime;

struct Vertex{
    int end;
    int clr;
    int parent;
    int beginning;
    vector<int> adj;
    
    Vertex(){
        parent = MaxInt;
        clr = 1;
    }
};

vector<Vertex*> verts;
vector<Vertex*> vert;

void Visit1(int index, vector<Vertex*> verts, bool crossway){
    tiempo++;
    verts[index] -> beginning = tiempo;
    verts[index] -> clr = 2;
    
    for (int f = 0; f < verts[index] -> adj.size(); f++){
        int adjcnt = verts[index] -> adj[f];
        
        if(verts[adjcnt] -> clr == 1){
            
            verts[adjcnt] -> parent = index;
            Visit1(adjcnt, verts, crossway);
        }
    }
    
    tiempo++;
    verts[index] -> clr = 3;
    verts[index] -> end = tiempo;
    
    if(!crossway){
        FinishTiempo.push_back(index);
    }
    else{
        TiempoFinishTime.push_back(index);
    }
}

void DFS1(vector<Vertex*> verts, bool crossway){
    if(crossway){
        tiempo = 0;
        for(int k = 0; k < verts.size(); k++){
            int t_index = FinishTiempo[verts.size() - k - 1];
            
            if(verts[t_index] -> clr == 1){
                Visit1 (t_index, verts, crossway);
            }
        }
    }
    
    else{
        for(int j = 0; j < verts.size(); j++){
            if(verts[j] -> clr == 1) {
                Visit1 (j, verts, crossway);
            }
        }
    }
}
bool ItIsRoot(int index){
    
    if(vert[index] -> parent == MaxInt){
        return true;
    }
    return false;
}

void SetingID(int index1, int index2){
    
    int Minimum = TiempoFinishTime[index1];
    
    for(int p = index1; p <= index2; p++){
        if (Minimum > TiempoFinishTime[p]){
            
            Minimum = TiempoFinishTime[p];
        }
    }
    for(int j = index1; j <= index2; j++){
        
        vect[TiempoFinishTime[j]] = Minimum;
    }
}

void print(){
    int idx = 0;
    
    for(int i = 0; i < TiempoFinishTime.size(); i++){
        
        if(ItIsRoot(TiempoFinishTime[i])){
            SetingID(idx, i);
            idx = i + 1;
        }
    }
    
    for(int j = 0; j < vect.size(); j++){
        cout << vect[j] << endl;
    }
}

int main(){
    int FirstVertex;
    int SecondVertex;
    int size;
    int edg;
    
    
    cin >> size >> edg;
    
    verts.resize(size);
    vert.resize(size);
    vect.resize(size);
    
    for(int m = 0; m < size; m++){
        verts[m] = new Vertex();
        vert[m] = new Vertex();
    }
    
    
    for(int n = 0; n < edg; n++) {
        cin >> FirstVertex;
        cin >> SecondVertex;
        verts[FirstVertex] -> adj.push_back(SecondVertex);
        vert[SecondVertex] -> adj.push_back(FirstVertex);
    }
    DFS1(verts, false);
    DFS1(vert, true);
    
    print();
    
}
