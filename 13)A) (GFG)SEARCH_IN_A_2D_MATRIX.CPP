// PROBLEM LINK --- https://leetcode.com/problems/search-a-2d-matrix/description/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/search-in-a-2d-matrix_980531

// IT ALSO WORKS FOR LEETCODE

#include<bits/stdc++.h> 
using namespace std;

bool search(vector<vector<int> > matrix, int n, int m, int x) 
{
    // code here 
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == x) return true;
            if(matrix[i][j] > x) break;
        }
    }
    return false ;
    */
    // OPTIMIZED APPROACH
    int i = 0 , j = m-1 ;
    while(i<n && j>=0){
        if(matrix[i][j] == x) return true ;
        if(matrix[i][j] > x) j-- ;
        else i++ ;
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
        int x ; cin >>x ;
        if (search(matrix,n,m,x)) cout << "1\n" ;   
        else cout << "0\n" ; 
    }
    return 0; 
} 
