#include <bits/stdc++.h>
using namespace std;

int secondlargestElement(vector<int> &nums){
    int largest = nums[0];
    int slargest = -1;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > largest){
            slargest = largest;
            largest = nums[i];
        }
        else if(nums[i] < largest && nums[i] > slargest){
            slargest = nums[i];
        }
    }
    return slargest;
}

int largestElement(vector<int> &nums)
{
    int largest = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > largest)
        {
            largest = nums[i];
        }
    }
    return largest;
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 2, 9};
    int large = largestElement(arr);
    int secondlarge = secondlargestElement(arr);
    cout << "The largest element in the array is : " << large << endl;
    cout << "The second largest element in the array is : " << secondlarge << endl;
    return 0;
}