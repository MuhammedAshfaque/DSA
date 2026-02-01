#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>&nums, int value){
    bool flag = false;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == value){
            flag = true;
        }
    }
    return flag;
}

// Time complexity with O(n^2) 
// int longestConsecutive(vector<int> &nums)
// {
//     int longest = 0;
//     for(int i = 0; i < nums.size(); i++){
//         int x = nums[i]; 
//         int count = 1;
//         while(linearSearch(nums, (x+1)) == true){
//             x++;
//             count++;
//         }
//         longest = max(longest, count);
//     }
//     return longest;

// }

// int longestConsecutive(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     int currcount = 0;
    
//     int longest = 1;
//     int lastSmaller = INT_MIN;
//     for(int i = 0; i < nums.size(); i++){
//         if((nums[i] - 1) == lastSmaller){
//             currcount++;
//             lastSmaller = nums[i];
//         }
//         else if(nums[i] != lastSmaller){
//             currcount = 1;
//             lastSmaller = nums[i];
//         }
//         longest = max(longest, currcount);
//     }
//     return longest;

// }

// Time complexity, for unorder set O(1) in average or best case. But O(n), when collision happen
int longestConsecutive(vector<int> &nums)
{
    int longest = 1;
    unordered_set<int> st;
    for(int i = 0; i < nums.size(); i++){
        st.insert(nums[i]);
    }
    for(auto it : st){
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                x++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

}

int main()
{
    vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    int ans = longestConsecutive(arr);
    cout<<"The answer is : "<<ans;
    return 0;
}