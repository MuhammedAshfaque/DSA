#include<bits/stdc++.h>
using namespace std;
// Memoization technique
// int fib(int n, vector<int>&dp){
//     if(n <= 1) return n;
//     if(dp[n] != -1) return dp[n];
//     return dp[n] = fib(n-2, dp)+fib(n-1, dp);
// }


int main(){
    int n = 5;
    // vector<int>dp(n+1, -1);
    // cout<<fib(n, dp);

    // Tabulation method
    int prev2 = 0, prev = 1;
    for (int i = 2; i <= n; i++)
    {
        int curri = prev2 + prev;
        prev2 = prev;
        prev = curri;
    }
    cout<<prev;
   return 0;
}