//  CSE 100: Algorithms
//  flira.cpp
//  Lab08
//
//  Created by Francisco Lira on 03/20/21.

#include <iostream>
using namespace std;

//I used the psesudo code, PrintOptimalParens(s, i, j) from the textbook.
void  PrintOptParens(int i, int j, int bracket, int *name)
{
    if (i == j)
    {
        //cout<<name++;
        cout << "A" << (i - 1);
        return;
        
    }
    else
        cout << "(";
    // This is ptting brackets aorund the subexpression recursivly.
    PrintOptParens(i, *((name+i*bracket)+j), bracket, name);
    PrintOptParens(*((name+i*bracket)+j) + 1, j, bracket, name);
    cout << ")";
    
}

//I used the psesudo code, MatrixChainOrder(p) from the textbook.
void MatrixChainOrder(int p[], int n)
{
    int m[n][n];
    int OptBrePnt[n][n]; //the vairable OptBrePnt is going to be storing the optimal break point
    int a, b, i, j, k;
    
    for (i = 1; i < n; i++)
    {
        m[i][i] = 0;
        
    }
    
    for (a = 2; a < n; a++)   //the variable a is the chain length (a = chain length)
    {
        for (i = 1; i < n - a + 1; i++)
        {
            j = i + a - 1;
            m[i][j] = 123456789; // This is infinity
            
            for (k = i; k <= j - 1; k++)
            {
                b = m[i][k] + m[k + 1][j] + ((p[i - 1]) * (p[k])* (p[j]));
                if (b < m[i][j])
                {
                    m[i][j] = b;
                    OptBrePnt[i][j] = k;//This is the index for optimal split!
                    
                }
                
            }
            
        }
        
    }
    
    //returning m and s
    
    cout << m[1][n - 1];
    cout << endl;
    
    PrintOptParens(1, n - 1, n, (int *)OptBrePnt);
    cout << endl;
}

int main()
{
    int f;
    cin >> f;
    int * arr = new int[f];
    
    for (int i = 0; i <= f; i++)
    {
        cin >> arr[i];
    }
    
    MatrixChainOrder(arr, f + 1);
    return 0;
    
}
