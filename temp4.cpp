#include<bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int>s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s2.push(x);
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        swap(s1, s2);
        // cout << "" << s2.empty();
    }
    
    int pop() {
        int topElement = s1.top();
        s1.pop();
        return topElement;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};
bool check(vector<int>& nums) {
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n]) {
            count++;
        }
        if (count > 1) return false;
    }
    cout << count << endl;
    return true;
}
int main(){

    // MyQueue q;
    // q.push(4);
    // q.push(6);

    // cout << q.peek() << endl;
    // cout<< q.pop() << endl;
    // cout<< q.pop() << endl;

    vector<int>nums = {1, 2, 3, 4, 5};
    cout << check(nums);
    
   return 0;
}