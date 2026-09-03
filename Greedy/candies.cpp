#include <bits/stdc++.h>
using namespace std;

int candy(vector<int> &ratings)
{
    int n = ratings.size();

    vector<int> candies(n, 1);
    // For left child
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && ratings[i] > ratings[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }
    
    for(auto it: candies){
        cout<< it<< " ";
    }
    cout<<endl;
    // For right child
    for (int i = n - 1; i >= 0; i--)
    {
        if (i < n - 1 && ratings[i] > ratings[i + 1])
        {
            candies[i] = candies[i + 1] + 1;
        }
    }
    for(auto it: candies){
        cout<< it<< " ";
    }
    int totalCandies = 0;
    for (int i = 0; i < n; i++)
    {
        totalCandies += candies[i];
    }
    return totalCandies;
}

int main()
{
    vector<int>nums = {1, 3, 4, 5, 2};
    candy(nums);
    return 0;
}