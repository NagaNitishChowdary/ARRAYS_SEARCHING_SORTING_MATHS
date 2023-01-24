// PROBLEM LINK --- https://leetcode.com/problems/set-matrix-zeroes/description/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_3846774

#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    // BRUTEFORCE 
    /*
    vector<vector<int>>matrix1=matrix;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0){
                for(int i1=0;i1<matrix[0].size();i1++) matrix1[i][i1]=0;
                for(int j1=0;j1<matrix.size();j1++) matrix1[j1][j]=0;
            }   
        }
    }   
    matrix=matrix1 ;
    */
    // OPTIMIZED APPROACH 
    int col0 = 1 , n = matrix.size() , m = matrix[0].size() ;
    for(int i=0 ; i<n ; i++){
        if(matrix[i][0] == 0) col0 = 0 ;
        for(int j=1 ; j<m ; j++){
            if(matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0 ;
        }
    }

    for(int i=n-1 ; i>=0 ; i--){
        for(int j=m-1 ; j>=1 ; j--){
            if((matrix[i][0] == 0) || matrix[0][j] == 0) matrix[i][j] = 0 ;
        }
        if(col0 == 0) matrix[i][0] = 0 ;
    }
}

int main(){
    int tc ; cin >> tc ;
    while(tc--){
        int n,m ; cin >> n >> m ;
        vector<vector<int>> matrix(n,vector<int>(m)) ;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                cin >> matrix[i][j] ;
            }
        }
        setZeroes(matrix) ;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++) cout << matrix[i][j] << " " ;
            cout << endl ;
        }
    }
    return 0;
}
