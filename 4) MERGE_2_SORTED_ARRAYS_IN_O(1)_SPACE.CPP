// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/merge-two-sorted-arrays-without-extra-space_6898839

#include <bits/stdc++.h> 
using namespace std; 

void merge(long long arr1[], long long arr2[], int n, int m) 
{ 
    // code here 
    // USING INSERTION SORT ALGORITHM 
    /*
    long long i = 0 , j = 0 ;
    for(int i=0 ; i<n ; i++){
        if(arr1[i] > arr2[0]){
            swap(arr1[i] , arr2[0]) ;
            int first = arr2[0] ;
            // move arr2[0] to its correct position to maintain the sorted
            // order of arr2[]. Note: arr2[1…n-1]` is already sorted
            int k ;
            for(k=1 ; k<m && arr2[k]<first ; k++) arr2[k-1] = arr2[k] ;
            arr2[k-1] = first ;
        }
    }
    */
    
    // GAP METHOD
    int gap = ((n+m)%2 == 0)? (n+m)/2 : (n+m)/2+1 ;
    while(gap>0){
        int i = 0 , j = gap ;
        while(j < (n+m)){
            if(j<n && (arr1[i] > arr1[j])) swap(arr1[i] , arr1[j]) ;
            else if(j>=n && i<n && (arr1[i] > arr2[j-n])) swap(arr1[i] , arr2[j-n]) ;
            else if(j>=n && i>=n && (arr2[i-n] > arr2[j-n])) swap(arr2[i-n] , arr2[j-n]) ;
            j++ ; i++ ;
        }
        if(gap == 1) gap = 0 ;
        else gap = ceil((float)gap/2) ;
    }
} 

int main() 
{ 
    int T ; cin >> T ;
    while(T--){
        int n, m ;
        cin >> n >> m;
        long long arr1[n], arr2[m];
        for(int i = 0;i<n;i++) cin >> arr1[i] ;
        for(int i = 0;i<m;i++) cin >> arr2[i] ;
        merge(arr1, arr2, n, m); 
        for (int i = 0; i < n; i++) cout << arr1[i] << " " ; 
        for (int i = 0; i < m; i++) cout << arr2[i] << " " ;     
        cout<<endl;
    }
    return 0; 
} 
