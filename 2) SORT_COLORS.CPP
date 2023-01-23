// PROBLEM LINK --- https://leetcode.com/problems/sort-colors/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/sort-an-array-of-0s-1s-and-2s_892977

#include<bits/stdc++.h>
using namespace std ;

void sortColors(vector<int>& nums) {
    // APPROACH 1 --- SORTING
    /*
    sort(nums.begin() , nums.end()) ;
    */
    /*
    // APPROACH 2 --- USING COUNT SORT
    int size = nums.size() ;
    int one = 0 , zero = 0 , two = 0 ;
    for(int i=0 ; i<size ; i++){
        if(nums[i] == 0) zero++ ;
        else if(nums[i] == 1) one++ ;
        else two++ ;
    }
    // AFTER COUNTING WE CAN EASILY PLACE IT INTO THE ARRAY
    for(int i=0 ; i<zero ; i++) nums[i] = 0 ;
    for(int i=zero ; i<zero+one ; i++) nums[i] = 1 ;
    for(int i=zero+one ; i<zero+one+two ; i++) nums[i] = 2 ;
    */

    //  APPROACH 3 --- DUTCH NATIONAL FLAG ALGORITHM --- SINGLE 
    
    int n = nums.size() ;
    int low = 0 , mid = 0 , high = n-1 ;
    while(mid <= high){
        if(nums[mid] == 0) swap(nums[mid++] , nums[low++]) ;
        else if(nums[mid] == 1) mid++ ;
        else swap(nums[mid] , nums[high--]) ;
    }
    
}

int main()
{
    int t ; cin >> t ;
    while(t--){
        int n ; cin >> n ;
        vector<int> nums(n) ;
        for(int i=0 ; i<n ; i++) cin >> nums[i] ;
        sortColors(nums) ;
        for(int i=0 ; i<n ; i++) cout << nums[i] << " " ;
        cout << endl ;
    }
    return 0 ;
}
