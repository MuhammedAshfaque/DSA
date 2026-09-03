#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void updateFreq(int op, int val, vector<int>& freqBits) {
        int i = 0;
        while(val > 0) {
            if((val & 1)) {
                freqBits[i] += op; //+1 in case of adding and -1 in case of removing
            }

            val /= 2;
            i++;
        }
    }
    int minimumDifference(vector<int>& nums, int k) {
        vector<int> freqBits(32, 0);

        int n = nums.size();

        int i = 0;
        int j = 0;
        int windowAnd = nums[0];
        int result = INT_MAX;

        while(j < n) {
            windowAnd = windowAnd & nums[j];
            updateFreq(1, nums[j], freqBits);

            result = min(result, abs(k - windowAnd));

            if(windowAnd > k) { // we have to decrease the windowAnd.
                j++;
            } else if (windowAnd < k) { // we have to increase the windowAnd.
                while(i <= j && windowAnd < k) {
                    updateFreq(-1, nums[i], freqBits);
                    i++;
                    windowAnd = 0;
                    for(int b = 0; b < 32; b++){
                        if( (j-i+1) == freqBits[b]) { //jth bit of all numbers in the window (j-i+1) are set to 1
                            windowAnd = windowAnd | (1<<b);
                        }
                    }
                    result = min(result, abs(k-windowAnd));
                }
                j++;
            } else {
                return 0; //we have found a subarray with AND equal to k, so the minimum difference is 0
            }
        }

        return result;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    int k = 2;
    cout << sol.minimumDifference(nums, k) << endl; // Output the minimum difference
    return 0;
}