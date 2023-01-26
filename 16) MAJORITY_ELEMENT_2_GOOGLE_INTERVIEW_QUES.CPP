// PROBLEM LINK --- https://leetcode.com/problems/majority-element-ii/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/majority-element-ii_893027

#include<bits/stdc++.h> 
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    // APPROACH 1 --- USE HASHMAP
    /*
    map<int,int> mpp ;
    int size = nums.size() ;
    for(auto it:nums) mpp[it]++ ;
    vector<int> ans ;
    for(auto it:mpp) if(it.second > size/3) ans.emplace_back(it.first) ;
    return ans ;
    */
    // APPROACH 2 --- BOYER MOORE VOTING ALGORITHM 
    // WE CAN HAVE ATMOST 2 ELEMENTS WHICH OCCUR >(N/3) TIMES 
    int cnt1 = 0 , cnt2 = 0 , ele1 = INT_MIN , ele2 = INT_MIN ;
    int size = nums.size() ;
    for(int i=0 ; i<size ; i++){
        if(nums[i] == ele1) cnt1++ ;
        else if(nums[i] == ele2) cnt2++ ;
        else if(cnt1 == 0){
            ele1 = nums[i] ; cnt1 = 1 ;
        }
        else if(cnt2 == 0){
            ele2 = nums[i] ; cnt2 = 1 ;
        }
        else{
            cnt1-- ; cnt2-- ;
        }
    }
    vector<int> ans ;
    cnt1 = cnt2 = 0 ;
    for(auto it:nums){
        if(it == ele1) cnt1++ ;
        if(it == ele2) cnt2++ ;
    }
    if(cnt1 > size/3) ans.emplace_back(ele1) ;
    if(cnt2 > size/3) ans.emplace_back(ele2) ;
    return ans ;
}

int main() 
{ 
    int t ; cin >> t ;
    while(t--){
        int n ; cin >> n ;
        vector<int> nums(n) ;
        for(int i=0 ; i<n ; i++) cin >> nums[i] ;
        vector<int> ans = majorityElement(nums) ;
        for(auto it:ans) cout << it << " " ; cout << endl ;
    }
    return 0; 
} 
