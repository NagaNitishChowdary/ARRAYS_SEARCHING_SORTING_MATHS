// PROBLEM LINK --- https://leetcode.com/problems/next-permutation/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/next-permutaion_893046
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/next-permutation5226/1

#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(int N, vector<int> arr){
    // code here
    // APPROACH --- 1 
    // next_permutation(arr.begin() , arr.end());
    // return arr ;
    
    // APPROACH --- 2
    int k , l ;
    // k --- first break point , l --- second break point 
    for(k=N-2 ; k>=0 ; k--){
        if(arr[k] < arr[k+1]) break ;
    }
    if(k<0){
        reverse(arr.begin() , arr.end()) ;
    } else {
        for(l=N-1 ; l>k ; l--){
            if(arr[l] > arr[k]) break ;
        }
        swap(arr[k] , arr[l]) ;
        reverse(arr.begin()+k+1 , arr.end()) ;
    }
    return arr ;
}

int main(){
    int t ; cin >> t ;
    while(t--){
        int N ; cin >> N ;
        vector<int> arr(N) ;
        for(int i = 0;i < N;i++) cin >> arr[i] ;
        vector<int> ans = nextPermutation(N, arr);
        for(int u: ans) cout << u << " " ;
        cout << "\n" ;
    }
    return 0;
}
