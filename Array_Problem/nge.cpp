#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int>ng(n, 0);
    for(int i = 0; i < n; i++){
        int j = i % n;
        int idx = i;
        while(j < n){
            if(nums[i] < nums[j]){
                ng[i] = nums[j];
            }
            idx++;
            j = idx % n;
        }
        if(ng[i] == 0) ng[i] = -1;
    }
    return ng;
}
int main(){
//     vector<int>nums = {1,2,1};
//     vector<int>ans = nextGreaterElements(nums);
//     for(auto it : ans){
//         cout<< it << endl;
//     }
    int x = ~(5);
    // cout<< x;

    // int a = 9, b = 3;
    // cout<< a << " " << b << endl;
    // a = a^b;
    // b = a^b;
    // a = a^b;
    // cout<< a << " " << b << endl;

    // if((13 >> 2) & 1 == 0){
    //      cout << "Yes set";
    // }
    // int s = max(-1 , 0);
    int s = 1 << 0;
    cout<<s;
   return 0;
}