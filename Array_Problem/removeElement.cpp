#include<bits/stdc++.h>
using namespace std;
void removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    int count = 0;
    for(int i = 0; i < n; i++){
        while(nums[i] == val){
            count++;
            int j = i;
            while(j < n-1){
                nums[j] = nums[j+1];
                j++;
            }
        }
    }
    for (auto it : nums)
    {
        cout << it << " ";
    }
    // return nums.size() - count;
}
int main(){
    vector<int>nums = {0,1,2,2,3,0,4,2};
    int value = 2;
    removeElement(nums, value);
    
    
   return 0;
}