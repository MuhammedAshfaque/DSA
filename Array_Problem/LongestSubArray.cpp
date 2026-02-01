#include<bits/stdc++.h>
using namespace std;
// Brute approach
// int LongestSubArraywithwithSumk(int arr[], int n, int x){
//     int maxlen = 0;
//     for(int i = 0; i < n; i++){
//         int sum = 0;
//         for(int j = i; j < n; j++){
//             sum += arr[j];
//             if(sum == x){
//                 int len = j-i+1;
//                 maxlen = max(len ,maxlen);
//             }
//         }
//     }
//     return maxlen;
// }

int LongestSubArraywithwithSumk(int arr[], int n, int k){
    int maxlen = 0;
    int prefSum = 0;
    map<int,int>mpp;
    mpp[0] = -1;
    for(int i = 0; i < n; i++){
        prefSum += arr[i];
        int rem = prefSum - k; 
        
        if(mpp.find(rem) != mpp.end()){
            int len = i - mpp[rem];
            maxlen = max(len, maxlen);
        }
        if(mpp.find(prefSum) == mpp.end()){
            mpp[prefSum] = i;
        }
    }
    return maxlen;
}

int main(){
    int arr[] = {1, 2, 3, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 4, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int length = LongestSubArraywithwithSumk(arr, n, k);
    cout<<length;
    return 0;
}
