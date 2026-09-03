#include<bits/stdc++.h>
using namespace std;
class Solution {
    void solve(int idx, int n, string temp, vector<string>& nums){
        if(idx > 0 && temp[idx] == temp[idx-1]){
            return;
        }
        if(temp.length() == n){
            nums.push_back(temp);
            return;
        }
        solve(idx+1, n, temp+"a", nums);
        solve(idx+1, n, temp+"b", nums);
        solve(idx+1, n, temp+"c", nums);
       
    }
public:
    string getHappyString(int n, int k) {
        vector<string>nums;
        solve(-1, n, "", nums);
        if(nums.size() < k){
            return "";
        }
        return nums[k-1];
    }
};
int main(){
   Solution s;
   cout << s.getHappyString(3, 9) << endl;
   return 0;
}
