#include <bits/stdc++.h>
using namespace std;

/*Pick pivot and place it in its correct position such that all smaller elements are on left and greater elements are on the right*/


// int getPartition(vector<int> &nums, int low, int high){
//     int pivot = nums[low];
//     int i = low;
//     int j = high;
//     while(i < j){
//         while(nums[i] <= pivot && i <= high-1){
//             i++;
//         }
//         while(nums[j] > pivot && j >= low+1){
//             j--;
//         }
//         // Here we got the value smaller, and greater. If it is present into range i<j
//         if(i < j){
//             swap(nums[i], nums[j]);
//         }
//     }
//     // We can swap with pivot, but we don't. Because pivot is local variable, so in the main nums array, doesn't reflect
//     swap(nums[low], nums[j]);
//     return j;
// }

// void quickSort(vector<int> &nums, int low, int high)
// {
//     if (low < high)
//     {
//         int pIndex = getPartition(nums, low, high);
//         quickSort(nums, low, pIndex-1); 
//         quickSort(nums, pIndex+1, high);
//     }
// }










int getPartition(int low, int high, vector<int>&nums){
    int pivot = nums[low];
    int i = low;
    int j = high;

    while(i < j){
        while(i < high && nums[i] <= pivot){
            i++;
        }
        while(j >= low + 1 && nums[j] > pivot){
            j--;
        }
        if(i < j){
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[low], nums[j]);
    return j;
}

void quickSort(int low, int high, vector<int>&nums){
    if(low >= high){
        return;
    }
    int pIdx = getPartition(low, high, nums);
    quickSort(low, pIdx - 1, nums);
    quickSort(pIdx + 1, high, nums);
}


int main()
{
    // vector<int> arr = {4,3,0,2,5,70,9,1,6};
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    quickSort(0, arr.size() - 1, arr);

    for (int x : arr)
        cout << x << " ";

    return 0;
}