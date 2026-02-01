
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class BSTIterator {
    vector<int>inorder;
private:
    void inordertraverse(TreeNode* root, vector<int>&inorder){
        if(root == NULL) return;
        inordertraverse(root -> left, inorder);
        inorder.push_back(root -> val);
        inordertraverse(root -> right, inorder);
    }
public:
    BSTIterator(TreeNode* root) {
        TreeNode* dummy = root;
        inordertraverse(dummy, inorder);
    }
    
    int next() {
        int val = inorder[0];
        inorder.erase(inorder.begin());
        return val;
    }
    
    bool hasNext() {
        if(inorder.empty()) return false;
        return true;
    }
};
int main(){
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator* bSTIterator = new BSTIterator(root);
    cout << bSTIterator -> next() << endl;    // return 3
    cout << bSTIterator -> next() << endl;    // return 7
    cout << bSTIterator -> hasNext() << endl; // return True
    cout << bSTIterator -> next() << endl;    // return 9
    cout << bSTIterator -> hasNext() << endl; // return True
    cout << bSTIterator -> next() << endl;    // return 15
    cout << bSTIterator -> hasNext() << endl; // return True
    cout << bSTIterator -> next() << endl;    // return 20
    cout << bSTIterator -> hasNext() << endl; // return False
   return 0;
}