#include<bits/stdc++.h>
using namespace std;
void findUnion(vector<int>&a, vector<int>&b){
    int i = 0, j = 0;
    vector<int> ans;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            if (ans.empty() || ans.back() != a[i])
                ans.push_back(a[i]);
            i++;
        }
        else if (a[i] > b[j]) {
            if (ans.empty() || ans.back() != b[j])
                ans.push_back(b[j]);
            j++;
        }
        else { // equal
            if (ans.empty() || ans.back() != a[i])
                ans.push_back(a[i]);
            i++;
            j++;
        }
    }

    // remaining elements
    while (i < a.size()) {
        if (ans.back() != a[i])
            ans.push_back(a[i]);
        i++;
    }

    while (j < b.size()) {
        if (ans.back() != b[j])
            ans.push_back(b[j]);
        j++;
    }
    for (auto it : ans)
    {
        cout<< it << " ";
    }

}
int main(){
    vector<int>nums1 = {1, 1, 2, 3, 4, 5};
    vector<int>nums2 = {2, 3, 4, 4, 5, 6};
    findUnion(nums1, nums2);
    
    
   return 0;
}