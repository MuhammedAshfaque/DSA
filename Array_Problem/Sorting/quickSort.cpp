#include <bits/stdc++.h>
using namespace std;

/*Pick pivot and place it in its correct position such that all smaller elements are on left side and greater elements are on right side*/


int getPartition(vector<int> &nums, int low, int high){
    int pivot = nums[low];
    int i = low;
    int j = high;
    while(i < j){
        while(nums[i] <= pivot && i <= high-1){
            i++;
        }
        while(nums[j] > pivot && j >= low+1){
            j--;
        }
        // Here we got the value smaller, and greater. If it is present into range i<j
        if(i < j){
            swap(nums[i], nums[j]);
        }
    }
    // We can swap with pivot, but we don't. Because pivot is local variable, so in the main nums array, doesn't reflect
    swap(nums[low], nums[j]);
    return j;
}

void quickSort(vector<int> &nums, int low, int high)
{
    if (low < high)
    {
        int pIndex = getPartition(nums, low, high);
        quickSort(nums, low, pIndex-1); 
        quickSort(nums, pIndex+1, high);
    }
}

int main()
{
    vector<int> arr = {4,3,0,2,5,7,9,1,6};
    quickSort(arr, 0, arr.size() - 1);

    for (int x : arr)
        cout << x << " ";

    return 0;
}