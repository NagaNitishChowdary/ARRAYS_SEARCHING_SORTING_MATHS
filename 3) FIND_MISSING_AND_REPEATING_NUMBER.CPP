// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/missing-and-repeating-numbers_873366?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std ;

vector<int>missing_repeated_number(vector<int> &nums) {
    int len = nums.size();

    int S = (len * (len+1) ) /2;
    int P = (len * (len +1) *(2*len +1) )/6;
    int missingNumber=0, repeating=0;
     
    for(int i=0 ; i<nums.size() ; i++){
       S -= (int)nums[i];
       P -= (int)nums[i] * (int)nums[i];
    }
     
    missingNumber = (S + P/S)/2;

    repeating = missingNumber - S;

    return {repeating , missingNumber};
}


int main()
{
    int t ; cin >> t ;
    while(t--){
        int n ; cin >> n ;
        vector<int> nums(n) ;
        for(int i=0 ; i<n ; i++) cin >> nums[i] ;
        vector<int> knnc = missing_repeated_number(nums) ;
        for(auto it:knnc) cout << it << " " ;
        cout << endl ;
    }
    return 0 ;
}
