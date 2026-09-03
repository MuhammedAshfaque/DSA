#include <bits/stdc++.h>
using namespace std;
// range sum query using segment tree
class SegmentTree {
    vector<int> segment;
    int n; 
public:
    SegmentTree(vector<int> &nums){
        n = nums.size();
        segment.assign(4 * n, 0);
        buildSegmentTree(0, 0, n - 1, nums);
    }
    void buildSegmentTree(int treeIndex, int left, int right, vector<int> &nums){
        if (left == right){
            segment[treeIndex] = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildSegmentTree(2 * treeIndex + 1, left, mid, nums);
        buildSegmentTree(2 * treeIndex + 2, mid + 1, right, nums);
        segment[treeIndex] = segment[2 * treeIndex + 1] + segment[2 * treeIndex + 2];
    }

    int query(int treeIndex, int l, int r, int start, int end){
        if (end < l  || start > r){
            return 0;
        }
            
        if (start <= l && end >= r){
            return segment[treeIndex];
        }

        int mid = l + (r - l) / 2;
        int leftSum = query(2 * treeIndex + 1, l, mid, start, end);
        int rightSum = query(2 * treeIndex + 2, mid + 1, r, start, end);
        return leftSum + rightSum;
    }
    int rangeSum(int start, int end){
        return query(0, 0, n - 1, start, end);
    }
};
int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    SegmentTree st(nums);
    cout << "Sum of values in given range = " << st.rangeSum(1, 3) << endl;  //15
    cout << "Sum of values in given range = " << st.rangeSum(0, 5) << endl;  //36
    cout << "Sum of values in given range = " << st.rangeSum(2, 4) << endl;  //21
    return 0;
}