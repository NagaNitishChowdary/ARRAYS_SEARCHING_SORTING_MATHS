// PROBLEM LINK --- https://leetcode.com/problems/find-the-duplicate-number/description/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    // APPROACH - 1 --- SORTING AND CHECKING PREV NUMBER AND CURR NUMBER 
    // APPROACH - 2 --- HASHING 
    // USING EXTRA SPACE 
    /*
    map<int,int> mpp ;
    int n = nums.size() ;
    for(auto it:nums) mpp[it]++ ;
    for(auto it:mpp){
        if(it.second>1) return it.first ;
    }
    return -1 ;
    */
    // OPTIMIZED APPROACH 
    // WITH OUT USING EXTRA SPACE 
    // USES LINKED LIST CYCLE METHOD 
    int slow = nums[0] , fast = nums[0] ;
    do{
        // TORTOISE METHOD
        slow = nums[slow] ;
        fast = nums[nums[fast]] ;
    } while(slow != fast) ;
    // NEXT STEP 
    fast = nums[0] ;
    while(slow != fast){
        slow = nums[slow] ;
        fast = nums[fast] ;
    }
    return slow ;
}

int main() {
    int t ; cin >> t ;
    while (t--) {
        int n ; cin >> n ;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x ; cin >> x ;
            nums.emplace_back(x);
        }
        cout << findDuplicate(nums) << endl;
    }
    return 0;
}
