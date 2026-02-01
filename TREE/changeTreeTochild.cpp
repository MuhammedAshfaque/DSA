#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};
        //        40
        //      /    \
        //     10     20
        //    /  \    / \
        //   2    5  30  40
// This is a algo that converts the tree which will follow the child sum rule..It will convert into like this 
        //        150
        //       /   \
        //     80     70
        //    /  \    / \
        //   40   40  30  40
void changeTree(TreeNode* root){
    if(root == NULL) return;
    int child = 0;
    if(root -> left) child += root -> left -> val;
    if(root -> right) child += root -> right -> val;
    if(child >= root->val) root -> val = child;
    else{
        if(root->left)  root->left->val = root->val;
        else if(root->right) root->right->val = root->val;
    }
    changeTree(root -> left);
    changeTree(root -> right);
    int tot = 0;
    if(root -> left) tot += root ->left ->val;
    if(root -> right) tot += root ->right ->val;
    if(root -> left || root -> right) root->val = tot;
}
void levelOrder(TreeNode* root) {
    if(!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            TreeNode* node = q.front(); q.pop();
            cout << node->val << " ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout << "\n";
    }
}

int main(){
    TreeNode* root = new TreeNode(40);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(40);
    levelOrder(root);
    changeTree(root);
    levelOrder(root);
   return 0;
}