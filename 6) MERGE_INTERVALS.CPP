// PROBLEM LINK --- https://leetcode.com/problems/merge-intervals/description/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/merge-intervals_699917

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
     // Code here
    vector<vector<int>> mergedIntervals ;
    int n = intervals.size() ;
    sort(intervals.begin() , intervals.end()) ;
    vector<int> temp = intervals[0] ;
    for(int i=1 ; i<n ; i++){
        if(intervals[i][0] <= temp[1]) temp[1] = max(intervals[i][1],temp[1]) ;
        else{
            mergedIntervals.push_back(temp) ;
            temp = intervals[i] ;
        }
    }
    mergedIntervals.push_back(temp) ;
    return mergedIntervals ;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<vector<int>>Intervals(n);
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            Intervals[i].push_back(x);
            Intervals[i].push_back(y);
        }
        vector<vector<int>> ans = overlappedInterval(Intervals);
        for(auto i: ans){
            for(auto j: i){
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

