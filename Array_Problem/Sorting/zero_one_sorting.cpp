#include <bits/stdc++.h>
using namespace std;
int minMoves(vector<int> arr)
{
    int n = arr.size();
    int lastZero = -1;
    int swaps1 = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (lastZero != -1 && arr[i] == 1)
        {
            swap(arr[lastZero], arr[i]);
            swaps1 += abs(lastZero - i);
            lastZero--;
        }
        if (lastZero == -1 && arr[i] == 0)
        {
            lastZero = i;
        }
    }
    int swaps2 = 0;
    int lastOne = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (lastOne != -1 && arr[i] == 0)
        {
            swap(arr[lastOne], arr[i]);
            swaps2 += abs(lastOne - i);
            lastOne--;
        }
        if (lastOne == -1 && arr[i] == 1)
        {
            lastOne = i;
        }
    }
    return min(swaps1, swaps2);
}
int main()
{
    vector<int> arr = {1, 1, 1, 1, 0, 0, 0, 0};
    cout << minMoves(arr);
    return 0;
}