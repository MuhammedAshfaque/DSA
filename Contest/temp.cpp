// You are given an array arr of length n representing the target display value at each Amazon fulfillment station (stations are in a line from left to right). 
// You can perform the following operations any number of times (possibly zero): 
// Choose an index i with 1 ≤ i ≤ n - 1 and set all positions 0, 1, ..., i - 1 to arr[i]. This operation costs: i * arr[i] 
// Choose an index i with 0 ≤ i ≤ n - 2 and set all positions i + 1, i + 2, ..., n - 1 to arr[i]. This operation costs: 
// (n - 1 - i) * arr[i]
// Compute the minimum total cost to make all array elements equal.

// Example
// n = 4
// arr = [3, 1, 4, 2]

// One optimal sequence is:

// Choose i = 1 and set position 0 to arr[1] = 1.
// Cost = 1 * 1 = 1

// Array becomes:

// [1, 1, 4, 2]

// Choose i = 1 and set positions 2 and 3 to arr[1] = 1.
// Cost = (4 - 1 - 1) * 1 = 2

// Array becomes:

// [1, 1, 1, 1]

// Total cost = 1 + 2 = 3.

// No sequence yields a smaller total cost.

#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>nums = {3, 1, 4, 2};
    int n = 4;
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int cost1 = i * nums[i];
        int cost2 = (n-1-i) * nums[i];
        int totalCost = cost1 + cost2;
        ans = min(ans, totalCost);
    }
    cout<<ans;
   return 0;
}
