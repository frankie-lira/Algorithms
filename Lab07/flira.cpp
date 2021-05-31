//  CSE 100: Algorithms
//  flira.cpp
//  Lab07
//
//  Created by Francisco Lira on 03/20/21.
#include<iostream>

using namespace std;
int MinInd = 0;
int MinInd2 = 0;

//referenced  memoized cut rod from the text book
int MCutRod(int p[],int size)
{
    int i;
    int j;
    int g;
    int temporary[size + 1];
    temporary[0] = 0;
    
    for(i = 1; i <= size; ++i)
    {
        g = INT_MIN;
        for(j = 0; j < i; ++j)
        {
            //max returns the largest variable
            if(g < max(g, p[j] + temporary[i - j - 1]))
            {
                MinInd = j;
                MinInd2 = i - j - 1;
            }
            //max returns the largest variable
            g = max(g, p[j] + temporary[i - j - 1]);
        }
        temporary[i] = g;
    }
    return temporary[size];
}

int main()
{
    int n;
    cin >> n;
    
    int i = 0;
    int p[n];
    
    while(i < n)
    {
        cin >> p[i++];
        
    }
    cout << MCutRod(p,n) << endl;
    
    if (MinInd2 == 0)
        cout << MinInd + 1 << " " << " -1" << endl;
    
    else
        cout << MinInd + 1 << " " << MinInd2 << " -1" << endl;
    
    return 0;
}


