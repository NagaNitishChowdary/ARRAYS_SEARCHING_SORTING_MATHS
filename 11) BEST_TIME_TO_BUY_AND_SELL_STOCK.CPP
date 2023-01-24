// PROBLEM LINK --- https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices){
    int mini = INT_MAX , profit = 0 ;
    int n = prices.size() ;
    for(int i=0 ; i<n ; i++){
        mini = min(mini , prices[i]) ;
        profit = max(profit , prices[i] - mini) ;
    }
    return profit ;
}

int main(){
    int t ; cin >> t ;
    while(t--){
        int N ; cin >> N ;
        vector<int> prices(N) ;
        for(int i = 0;i < N;i++) cin >> prices[i] ;
        cout << maxProfit(prices) << endl ;
    }
    return 0;
}
