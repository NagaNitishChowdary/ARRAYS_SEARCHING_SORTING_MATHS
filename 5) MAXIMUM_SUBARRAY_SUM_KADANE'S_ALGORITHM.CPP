// PROBLEM LINK --- https://leetcode.com/problems/maximum-subarray/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/maximum-subarray-sum_630526
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n){
    // APPROACH --- 1
    // CHECK FOR ALL SUBARRAYS --- O(N^3)
    /*
    long long maxi = INT_MIN ;
    for(int i=0 ; i<n ; i++){
        for(int j=i ; j<n ; j++){
            long long sum = 0 ;
            for(int k=i ; k<=j ; k++) sum += arr[k] ;
            maxi = max(maxi , sum) ;
        }
    }
    return maxi ;
    */
    // APPROACH --- 2     TC --- O(N^2)
    /*
    int maxi = INT_MIN ;
    for(int i=0 ; i<n ; i++){
        int sum = 0 ;
        for(int j=i ; j<n ; j++){
            sum += arr[j] ;
            maxi = max(maxi , sum) ;
        }
    }
    return maxi ;
    */
    // APPROACH ---3    TC --- O(N)
    long long sum = 0 , maxi = INT_MIN ;
    for(int it=0 ; it<n ; it++){
        sum += arr[it] ;
        maxi = max(sum,maxi) ;
        if(sum < 0) sum = 0 ;
    }
    return maxi ;
}

int main()
{
    int t,n;
    cin >> t ;
    while(t--){
        cin >> n; 
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i]; 
        cout << maxSubarraySum(a, n) << endl;
    }
}
