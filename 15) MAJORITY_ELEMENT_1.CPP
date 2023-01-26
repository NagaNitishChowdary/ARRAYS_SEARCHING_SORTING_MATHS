// PROBLEM LINK --- https://leetcode.com/problems/majority-element/description/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/majority-element_842495?leftPanelTab=0

#include<bits/stdc++.h> 
using namespace std;

int majorityElement(vector<int>& nums) {
    // APPROACH --- 1
    // TC --- O(NLOGN)    SC --- O(N)
    /*
    map<int,int>mpp;
    int n=nums.size();
    for(int i=0;i<n;i++) mpp[nums[i]]++;
    for(auto it:mpp) if(it.second>(n/2)) return it.first;
    return 0;
    */
    // MOORE VOTING ALGORITHM
    int ele = 0 , cnt = 0 ;
    for(auto it:nums){
        if(cnt == 0) ele = it ;
        if(ele != it) cnt++ ;
        else cnt-- ;
    }
    return ele ;
}

int main() 
{ 
    int t ; cin >> t ;
    while(t--){
        int n ; cin >> n ;
        vector<int> nums(n) ;
        for(int i=0 ; i<n ; i++) cin >> nums[i] ;
        cout << majorityElement(nums) << endl ;
    }
    return 0; 
} 
