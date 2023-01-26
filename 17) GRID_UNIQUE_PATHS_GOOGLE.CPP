// PROBLEM LINK --- https://leetcode.com/problems/unique-paths/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1

#include<bits/stdc++.h>
using namespace std;
    
int recursion1(int i,int j){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0 ) return 0;
    int up=recursion1(i-1,j);
    int left=recursion1(i,j-1);
    return up+left;
}

int memorization1(int i,int j,vector<vector<int>>&dp){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=memorization1(i-1,j,dp);
    int left=memorization1(i,j-1,dp);
    return dp[i][j]=up+left;
}

int NumberOfPath(int a, int b)
{
    int m = a , n = b ;
    //code here
    //int recursion=recursion1(m-1,n-1);
    //return recursion;
    //vector<vector<int>>dp(m,vector<int>(n,-1));
    //int memorization=memorization1(m-1,n-1,dp);
    //return memorization;
    
    // TABULATION
    /*
    int dp[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){ dp[i][j]=1; }
            else{
            int up=0,left=0;
            if(i>0) up=dp[i-1][j];
            if(j>0) left=dp[i][j-1];
            dp[i][j]=up+left;
            }
        }
    }
    return dp[m-1][n-1];
    
    */
    
    // SPACE OPTIMIZATION
    /*
    vector<int>prev(n,0);
    for(int i=0;i<m;i++){
        vector<int>temp(n,0);
        for(int j=0;j<n;j++){
            if(i==0 && j==0) temp[j]=1;
            else{
                int up=0,left=0;
                if(i>0) up=prev[j];
                if(j>0) left=temp[j-1];
                temp[j]=up+left;
            }
        }
        prev=temp;
    }
    return prev[n-1];
    */
    
    // MOST OPTIMIZED APPROACH --- USING COMBINATIONS
    int N = n+m-2 , r = m-1 ; // r can be n-1
    double res = 1 ;
    // WE ARE CALCULATION NCR
    for(int i=1; i<=r ; i++) res = res*(N-r+i)/i ;
    return (int)res ;
}

int main()
{
    int t ; cin >> t ;
    while(t--){
        int a , b ;
        cin >> a >> b ;
        cout << NumberOfPath(a,b) << endl;
    }
}
