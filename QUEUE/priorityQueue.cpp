#include <bits/stdc++.h>
using namespace std;

struct Item {
    int val;
    int priority;
};

// To store priority queue items 
vector<Item> pq;

// Function to insert element in priority queue
void enqueue(int val, int priority) {
    pq.push_back({val, priority});
}

// Function to get index of element with highest priority
int peek() {
    int ind = -1, maxPriority = INT_MIN;
    for (int i = 0; i < pq.size(); i++) {
        
        // Update index if a higher priority 
        // is found
        if (pq[i].priority > maxPriority || 
           (pq[i].priority == maxPriority && pq[i].val > pq[ind].val)) {
            maxPriority = pq[i].priority;
            ind = i;
        }
    }
    return ind;
}

// Function to remove the element with highest priority
void dequeue() {
    int ind = peek(); // Get index of highest priority element
    if (ind != -1) pq.erase(pq.begin() + ind);
}

int main() {
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(16, 4);
    enqueue(12, 3);

    cout << pq[peek()].val << endl; // 16
    dequeue();

    cout << pq[peek()].val << endl; // 14
    dequeue();

    cout << pq[peek()].val << endl; // 12
    return 0;
}