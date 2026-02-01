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
void inOrderTraversal(TreeNode* root){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->val;
    inOrderTraversal(root->right);

}
int main(){
    /* Construct the following tree
                1
              /   \
            2      3
           / \    /
          4   5  6 
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    inOrderTraversal(root);
   return 0;
}