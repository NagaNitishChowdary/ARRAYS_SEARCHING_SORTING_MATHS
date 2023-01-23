// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// PROBLEM LINK --- https://www.hackerrank.com/challenges/ctci-merge-sort/problem
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/count-inversions_615

#include <bits/stdc++.h>
using namespace std;
  
long long merge(long long low,long long mid,long long high,long long arr[],long long temp[]){
    // long long b[high+1] ;
    long long ans = 0 ;
    long long i = low , j = mid , k = low ;
    while(i <= (mid-1) && j <= high){
        if(arr[i] <= arr[j]) temp[k++] = arr[i++] ;
        else{ temp[k++] = arr[j++] ; ans += (mid-i) ; }
    }
    while(j <= high) temp[k++] = arr[j++] ;
    while(i <= mid-1) temp[k++] = arr[i++] ;
    for(int i=low ; i<=high ; i++) arr[i] = temp[i] ;
    return ans ;
}

long long mergeSort(long long low,long long high,long long arr[],long long temp[]){
    long long ans = 0 ;
    if(low < high){
        int mid = (low+high)/2 ;
        ans += mergeSort(low,mid,arr,temp) ;
        ans += mergeSort(mid+1,high,arr,temp) ;
        ans += merge(low,mid+1,high,arr,temp) ;
    }
    return ans ;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long temp[N] ;
    long long ans = mergeSort(0,N-1,arr,temp) ;
    return ans ;
}

int main() {
    long long T ; cin >> T ;
    while(T--){
        long long N ; cin >> N;
        long long A[N] ;
        for(long long i = 0;i<N;i++) cin >> A[i] ;
        cout << inversionCount(A,N) << endl;
    }   
    return 0;
}
