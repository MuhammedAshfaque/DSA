#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
void generateCombinations(int idx, vector<int>& arr, vector<int>& curr) {
    // Print current combination
    cnt++;
    if (!curr.empty()) {
        for (int x : curr) cout << x << " "; 
        cout << endl;
    }

    // Try adding next elements
    for (int i = idx + 1; i < arr.size(); i++) {
        curr.push_back(arr[i]);
        generateCombinations(i, arr, curr);
        curr.pop_back(); // backtrack
    }
}
class Solution {
private:
    void solve(int idx, int target, vector<int>& curr, vector<int>& candidates, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        if (target < 0 || idx == candidates.size()) return;

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            curr.push_back(candidates[i]);
            solve(i + 1, target - candidates[i], curr, candidates, ans);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        solve(0, target, curr, candidates, result);
        return result;
    }
};


int main() {
    vector<int> arr = {2,5,2,1,2};
    vector<int> curr;
    int count = 0;
    // for (int start = 0; start < arr.size(); start++) {
    //     count++;
    //     curr.clear();        // clear current combination
    //     curr.push_back(arr[start]); // start with current element
    //     generateCombinations(start, arr, curr);
    // }
    Solution s;
    vector<vector<int>>an = s.combinationSum2(arr, 5);
    for(auto subset : an){
        cout << "{ ";
        for(auto num : subset)
            cout << num << " ";
        cout << "}" << endl;
    }
    return 0;
}
