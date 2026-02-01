#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>>answ;
    void f(int idx, int target, vector<int>&curr, vector<int>& candidates){
        if (idx == candidates.size()) return;
        if(target == 0){
            answ.push_back(curr);
        }
        if(target < 0){
            return;
        }
        curr.push_back(candidates[idx]);
        f(idx, target - candidates[idx], curr, candidates);
        curr.pop_back();
        f(idx + 1, target, curr, candidates);
        
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        f(0, target, curr, candidates);

        set<vector<int>> uniqueComb;
        for (auto &v : answ) {
            uniqueComb.insert(v);
        }

        // convert back to vector
        vector<vector<int>> result(uniqueComb.begin(), uniqueComb.end());
        return result;
    }
};

int main(){
    vector<int>candidates = {2,3,6,7};
    int target = 7;
    Solution s;
    vector<vector<int>> ans = s.combinationSum(candidates, target);
    
    
    for (auto comb : ans){
        cout << "{ ";
        for (auto it : comb)
            cout << it << " ";
        cout << "}" << endl;
    }
    
   return 0;
}