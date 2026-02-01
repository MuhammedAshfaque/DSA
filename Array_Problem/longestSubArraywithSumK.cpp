#include <bits/stdc++.h>
using namespace std;
// It is for positive,0 as well as negative
// int longestSubarraySumK(vector<int> &nums, int k){
//     map<int, int> mpp;
//     int prefSum = 0;
//     int maxlen = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         prefSum += nums[i];
//         if (prefSum == k)
//         {
//             maxlen = max(maxlen, i + 1);
//         }
//         int remaining = prefSum - k;
//         if (mpp.find(remaining) != mpp.end())
//         {
//             int len = i - mpp[remaining];
//             maxlen = max(maxlen, len);
//         }
//         if (mpp.find(prefSum) == mpp.end())
//         {
//             mpp[prefSum] = i;
//         }
//     }
//     return maxlen;
// }

// It is the two pointer approach, only valid for 0 and +ve number
int longestSubarraySumK(vector<int> &nums, int k)
{
    int right = 0, left = 0;
    int prefSum = 0, maxLen = 0;
    while (right < nums.size())
    {
        prefSum += nums[right];
        while (left <= right && prefSum > k)
        {
            prefSum -= nums[left];
            left++;
        }
        if (prefSum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 1, 1, 4, 2, 3};
    int length = longestSubarraySumK(arr, 6);
    cout << "The Longest subArray size with maximum sum is : " << length;
    return 0;
}