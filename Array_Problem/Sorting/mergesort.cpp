#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>&nums, int low, int mid, int high){
    vector<int>temp;
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i = low; i <= high; i++){
        nums[i] = temp[i - low];
    }
    // for (int i = 0; i < temp.size(); i++) {
    //     nums[low + i] = temp[i];
    // }  same thing
}
void mergeSort(vector<int>&nums, int low, int high){
    if(low >= high) return;
    int mid = (low + high) /2;
    
    mergeSort(nums, low, mid);
    mergeSort(nums, mid+1, high);
    merge(nums, low, mid, high);
}

int main(){
    vector<int> arr = {64, 25, 12, 22, 11};
    mergeSort(arr, 0, arr.size()-1);

    for (int x : arr)
        cout << x << " ";

    return 0;
}
