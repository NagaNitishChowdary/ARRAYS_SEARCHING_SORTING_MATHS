// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/rotate-matrix-by-90-degrees_981261?leftPanelTab=0
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1

#include<bits/stdc++.h>
using namespace std;

// ROTATE MATRIX BY 90 DEGREES ANTI CLOCK WISE

vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix)
{
    // ALGORITHM 
    // STEP 1 --- TRANSPOSE THE GIVEN MATRIX 
    // STEP 2 --- REVERSE THE MATRIX
    int size = matrix.size() ;
    for(int i=0 ; i<size ; i++)
        for(int j=0 ; j<i ; j++)
            swap(matrix[j][i] , matrix[i][j]) ;
    reverse(matrix.begin() , matrix.end()) ;
    return matrix ;
}

int main(int argc,char const *argv[]) {
    int testCases ; cin >> testCases ;
    while(testCases--){
        int n ; cin >> n ;
        vector<vector<int>> matrix(n,vector<int>(n)) ;
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<n ; j++)
                cin >> matrix[i][j] ;
        vector<vector<int>> knnc = rotateMatrix(matrix) ;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++)
                cout << knnc[i][j] << " " ;
            cout << endl ;
        }
    }
    return 0;  
}
