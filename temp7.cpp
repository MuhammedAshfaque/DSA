#include<bits/stdc++.h>
using namespace std;
vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int n = nums.size();
    vector<int>prefXor(n, 0);
    prefXor[0] = nums[0];
    for(int i = 1; i < n; i++){
        prefXor[i] = prefXor[i-1] ^ nums[i];
    }
    vector<int>ans;
    int allowed = (1 << maximumBit); 
    for(int i = n - 1; i >= 0; i--){
        int k = 0;
        int xor_value = prefXor[i];
        for(int j = 30; j >= 0; j--){
            if((xor_value & (1 << j)) == 0){  // we can try to set this bit to 1
                int k_value = k | (1 << j);
                if(k_value < allowed){
                    k = k | (1 << j);
                }
            }
        }
        ans.push_back(k);
    }
    return ans;
}
int main(){
    vector<int> nums = {0, 1, 1, 3};
    int maximumBit = 2;
    vector<int> ans = getMaximumXor(nums, maximumBit);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}