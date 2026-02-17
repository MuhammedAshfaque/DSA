#include <bits/stdc++.h>
using namespace std;

// Pick elements one by one and insert them into sorted portion at correct position
vector<int> insertionSort(vector<int> &nums)
{
    for (int i = 1; i < nums.size() ; i++)
    {
        int j = i;
        while (j >= 1 && nums[j - 1] > nums[j])
        {
            int temp = nums[j-1];
            nums[j-1] = nums[j];
            nums[j] = temp;
            j--;
        }
    }
    return nums;
}

// Repeatedly swap adjacent elements if they are in wrong order. Shift large element to the end in each iteration
vector<int> bubbleSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        bool swapped = true;
        for (int j = 0; j < nums.size() - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = temp;
                swapped = false;
            }
        }
        if (swapped)
            break; // already sorted
    }
    return nums;
}

// Select minimum element from unsorted array and swap it with the first element of unsorted array
vector<int> selectionSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        int mindex = i;
        for (int j = i; j < nums.size(); j++)
        {
            if (nums[mindex] > nums[j])
            {
                mindex = j;
            }
        }
        // Swap nums[i] with nums[mindex]. Because mindex holds index of minimum element in unsorted array
        int temp = nums[mindex];
        nums[mindex] = nums[i];
        nums[i] = temp;
    }   // O(n^2)
    return nums;
}

int main()
{
    vector<int> arr = {64, 25, 12, 22, 11};
    // arr = selectionSort(arr);
    // arr = bubbleSort(arr);
    arr = insertionSort(arr);

    for (int x : arr)
        cout << x << " ";

    return 0;
}