#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {4, 3, 9, 2, 8, 7, 6};
    next_permutation(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    // v.erase(v.begin() + 1); // remove element at index 1 (20)

    // cout<<v.size() << endl;
    // for(int i = 0; i < v.size(); i++) {
    //     cout << v[i] << " ";
    // }

    // string temp = "";
    // int idx = 0;
    
    // cout << temp[idx] +"a";   
    return 0;
}