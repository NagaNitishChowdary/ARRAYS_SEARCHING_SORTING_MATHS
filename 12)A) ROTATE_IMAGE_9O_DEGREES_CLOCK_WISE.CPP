// PROBLEM LINK --- https://leetcode.com/problems/rotate-image/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/library/turn-an-image-by-90-degrees

#include<bits/stdc++.h>
using namespace std;

// ROTATE MATRIX BY 90 DEGREES CLOCK WISE

void rotate(vector<vector<int>>& matrix) {
    // ALGORITHM 
    // STEP 1 --- TRANSPOSE THE GIVEN MATRIX 
    // STEP 2 --- REVERSE THE ROWS IN THE MATRIX
    int size = matrix.size() ;
    for(int i=0 ; i<size ; i++)
        for(int j=0 ; j<i ; j++)
            swap(matrix[j][i] , matrix[i][j]) ;
    for(int i=0 ; i<size ; i++) 
        reverse(matrix[i].begin() , matrix[i].end()) ;
}

int main(int argc,char const *argv[]) {
    int testCases ; cin >> testCases ;
    while(testCases--){
        int n ; cin >> n ;
        vector<vector<int>> matrix(n,vector<int>(n)) ;
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<n ; j++)
                cin >> matrix[i][j] ;
        rotate(matrix) ;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++)
                cout << matrix[i][j] << " " ;
            cout << endl ;
        }
    }
    return 0;  
}
