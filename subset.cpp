#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    set<vector<int>>st;
    int n = nums.size();
    for(int i = 0; i < (1<<n); i++){
        vector<int>curr;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                curr.push_back(nums[j]);
            }
            
        }
        st.insert(curr);
    }
    for (auto it : st) {
        ans.push_back(it);
    }
    return ans;
}
// [[],[1],[1,4],[1,4,4],[1,4,4,4],[1,4,4,4,4],[4],[4,4],[4,4,4],[4,4,4,4]]
// [[],[1],[1,4],[4],[4,1],[4,1,4],[4,4],[4,4,1],[4,4,1,4],[4,4,4],[4,4,4,1],[4,4,4,1,4],[4,4,4,4]]
int main(){
    vector<int>nums = {4, 4, 4, 1, 4};
    // sort(nums.begin(), nums.end());
    vector<vector<int>>ans = subsets(nums);

    for(auto subset : ans){
        cout << "{ ";
        for(auto num : subset)
            cout << num << " ";
        cout << "}" << endl;
    }
   return 0;
}