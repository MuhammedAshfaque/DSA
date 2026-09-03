#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 2, 4, 6};

    vector<int> ans;

    int i = 0, j = 0;

    while(i < a.size() && j < b.size()) {
        if(a[i] < b[j]) {
            i++;
        }
        else if(a[i] > b[j]) {
            j++;
        }
        else {
            if(ans.empty() || ans.back() != a[i]) {
                ans.push_back(a[i]);
            }
            i++;
            j++;
        }
    }

    for(auto x : ans) {
        cout << x << " ";
    }

    return 0;
}