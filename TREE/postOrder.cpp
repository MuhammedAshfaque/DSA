#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    TreeNode* left;
    int val;
    TreeNode* right;
    TreeNode(int value){
        val = value;
        left = right = NULL;
    }
};
void iterativePostOrderUsingTwoStacks(TreeNode* root){
    if(root == NULL) return;
    stack<TreeNode*> st1, st2;
    st1.push(root);
    while(!st1.empty()){
        TreeNode* node = st1.top();
        st1.pop();
        st2.push(node);
        if(node->left != NULL) st1.push(node->left);
        if(node->right != NULL) st1.push(node->right);
    }
    while(!st2.empty()){
        cout << st2.top()->val << " ";
        st2.pop();
    }
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    iterativePostOrderUsingTwoStacks(root);
    return 0;
}