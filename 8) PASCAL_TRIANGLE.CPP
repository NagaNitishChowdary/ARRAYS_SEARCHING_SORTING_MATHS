// PROBLEM LINK --- https://leetcode.com/problems/pascals-triangle/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/pascal-triangle0652/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/pascal-s-triangle_1089580

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows) ;
    for(int i=0 ; i<numRows ; i++){
        ans[i].resize(i+1) ;
        ans[i][0] = ans[i][i] = 1 ;
        for(int j=1 ; j<i ; j++){
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j] ;
        }
    }
    return ans ;
}

int main(){
    int tc ; cin >> tc ;
    while(tc--){
        int n ; cin >> n ;
        vector<vector<int>> knnc = generate(n) ;
        for(auto vctr:knnc){
            for(auto it:vctr) cout << it << " " ;
            cout << endl ;
        }
    }
    return 0;
}
