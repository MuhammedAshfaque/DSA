#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};
bool getPath(TreeNode *root, vector<int>&arr, int x){
    if(root == NULL) return false;
    arr.push_back(root -> val);
    if(root -> val == x) return true;
    if((getPath(root->left, arr, x)) || (getPath(root -> right, arr, x))) return true;
    arr.pop_back();
    return false;
}

// Wrapper function to print path
void printPath(TreeNode* root, int x) {
    vector<int> arr;
    if (getPath(root, arr, x)) {
        cout << "Path to " << x << ": ";
        for (int v : arr) cout << v << " ";
        cout << endl;
    } else {
        cout << "No path found for " << x << endl;
    }
}

int main(){
     /* Construct the following tree
              1
             / \
            2   3
           / \  
          4   5  
             / \  
            6   7  
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(6);

    // Test cases
    printPath(root, 7);  // Expected: 1 2 5

   return 0;
}