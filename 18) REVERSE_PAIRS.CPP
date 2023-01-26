// PROBLEM LINK --- https://leetcode.com/problems/reverse-pairs/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/reverse-pairs_1112652
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/count-reverse-pairs/1?page=1&sortBy=newest&query=page1sortBynewest

#include <bits/stdc++.h>
using namespace std;

int merge(int low,int mid,int high,vector<int> &arr){
    int  j = mid+1 , ans = 0 ;
    for(int i=low ; i<=mid ; i++){
        while((j <= high) && (arr[i] > 2LL *arr[j])) j++ ;
        ans += (j-(mid+1)) ;
    }
    j = mid+1 ;
    int i = low , k = low ;
    vector<int> temp ;
    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]) temp.emplace_back(arr[i++]) ;
        else temp.emplace_back(arr[j++]) ;
    }
    while(j <= high) temp.emplace_back(arr[j++]) ;
    while(i <= mid) temp.emplace_back(arr[i++]) ;
    for(int i=low ; i<=high ; i++) arr[i] = temp[i-low] ;
    return ans ;
}

int mergeSort(int low,int high,vector<int>&arr){
    int ans = 0 ;
    if(low < high){
        int mid = (low+high)/2 ;
        ans += mergeSort(low,mid,arr) ;
        ans += mergeSort(mid+1,high,arr) ;
        ans += merge(low,mid,high,arr) ;
    }
    return ans ;
}

int countRevPairs(int n, vector<int> arr) {
    // Code here
    // BRUTEFORCE --- O(N^2)
    /*
    int cnt = 0 ;
    for(int i=0 ; i<n-1 ; i++){
        for(int j=i+1 ; j<n ; j++){
            long long int knnc = (long long int)arr[i] - 2*(long long int)(arr[j]) ;
            if(knnc > 0) cnt++ ;
        }
    }
    return cnt ;
    */
    // OPTIMIZED --- USING MERGE SORT
    return mergeSort(0,n-1,arr) ;    
}

int main() {
    int t ; cin >> t ;
    while (t--) {
        int n ; cin >> n ;
        vector<int> arr;
        for (int i = 0; i < n; ++i) {
            int x ; cin >> x ;
            arr.push_back(x);
        }
        cout << countRevPairs(n, arr) << endl;
    }
    return 0;
}
