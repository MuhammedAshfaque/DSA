#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &arr, int target) {
    int low = 0, high = arr.size()-1;
    int ans;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            ans = mid;
            // Look for small index on left
            high = mid-1;
        } 
        else {
            low = mid+1;
        }
    }
    return ans;
}
int upperBound(vector<int> &arr, int target) {
    int low = 0, high = arr.size()-1;
    int ans;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target) {
            ans = mid;
            // Look for small index on left
            high = mid-1;
        } 
        else {
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int>nums = {1,2,3,3,5,8,8,10,10,11};
    int ans = upperBound(nums,3);
    cout<<ans;
   return 0;
}