#include<bits/stdc++.h>
using namespace std;
vector<int> findTwoElement(vector<int>& arr){
    // code here
    int n = arr.size();
    vector<int> hash(n+1, 0);
    for(int i = 0; i < n; i++){
        hash[arr[i]]++;
    }
    int duplicate = 0;
    int missing = 0;
    for(int i = 1; i <= n; i++){
        if(hash[i] == 0){
            missing = i;
        }
        if(hash[i] == 2){
            duplicate = i;
        }
    }
    return {duplicate, missing};
}
int main(){
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    vector<int> result = findTwoElement(arr);
    cout << "Duplicate: " << result[0] << ", Missing: " << result[1] << endl;
   return 0;
}