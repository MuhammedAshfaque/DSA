#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Kadane's algorithm works for all negative numbers as well.
    vector<int>nums = {-1, -2, -3, -4, -1, -2, -1, -5, -4};
    int currSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < nums.size(); i++){
        currSum += nums[i];
        maxSum = max(maxSum, currSum);
        if(currSum < 0){
            currSum = 0;
        }
    }
    cout<< maxSum << endl;  // it will produce 0, does not work for all negative numbers.

    return 0;
}