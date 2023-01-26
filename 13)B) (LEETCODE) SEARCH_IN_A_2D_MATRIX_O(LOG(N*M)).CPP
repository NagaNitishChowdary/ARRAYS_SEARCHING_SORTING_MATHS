// PROBLEM LINK --- https://leetcode.com/problems/search-a-2d-matrix/description/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/search-in-a-2d-matrix_980531?leftPanelTab=0

#include<bits/stdc++.h> 
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // APPROACH 1 
    /*
    int m = matrix.size() , n = matrix[0].size() ;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==target) return true;
            if(matrix[i][j]>target) break;
        }
    }
    return false;
    */
    // OPTIMIZED APPROACH
    /*
    int n = matrix.size() , m = matrix[0].size() ;
    int i = 0 , j = m-1 ;
    while(i<n && j>=0){
        if(matrix[i][j] == target) return true ;
        if(matrix[i][j] > target) j-- ;
        else i++ ;
    } 
    return false ;
    */
    // MOST OPTIMIZED APPROACH 
    int n = matrix.size() , m = matrix[0].size() ;
    int low = 0 , high = n*m-1 ;
    while(low <= high){
        int mid = low + (high-low)/2 ;
        if(matrix[mid/m][mid%m] == target) return true ;
        if(matrix[mid/m][mid%m] < target) low = mid+1 ;
        else high = mid-1 ;
    }
    return false ;
}

int main() 
{ 
    int t ; cin >> t ;
    while(t--){
        int n, m;
        cin>> n >> m ;
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0) ;
            for( int j=0; j<m; j++) cin >> matrix[i][j] ;
        }
        int x ; cin >> x ;
        if (searchMatrix(matrix,x)) cout << "1\n" ;   
        else cout << "0\n" ; 
    }
    return 0; 
} 
