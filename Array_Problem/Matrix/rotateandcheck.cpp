#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>>mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>>target = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    bool flag = mat==target;
    cout<<flag<<endl;
   return 0;
}