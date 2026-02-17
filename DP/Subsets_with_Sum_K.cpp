#include<bits/stdc++.h>
using namespace std;
int perfectSum(vector<int>& arr, int target) {
    // code here
    int n = arr.size();
    vector<vector<int>>dp(n, vector<int>(target+1, 0)); 
    // return f(n-1, target, arr, dp);
    
    // Base case
    // if(arr[0] == 0)
    //     dp[0][0] = 2;   // pick / not pick
    // else
    //     dp[0][0] = 1;

    // if(arr[0] != 0 && arr[0] <= target)
    //     dp[0][arr[0]] = 1;
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }
    if(arr[0] <= target) dp[0][arr[0]] = 1;
    
    for(int i = 1; i < n; i++){
        for(int s = 1; s <= target; s++){
            int notPick = dp[i-1][s];
            int pick = 0;
            if(arr[i] <= s){
                pick = dp[i-1][s-arr[i]];
            }
            dp[i][s] = pick + notPick;
        }
    }
    return dp[n-1][target];
}
int main(){
    vector<int>nums{2, 5, 1, 4, 3};
    cout<<"Your output: "<<perfectSum(nums, 10)<<endl;
   return 0;
}