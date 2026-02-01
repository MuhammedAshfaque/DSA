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
void preInPostTraversal(TreeNode* root){
    if(root == NULL) return;
    stack<pair<TreeNode*, int>> st;
    st.push({root ,1});
    vector<int>pre, post, in;
    if(root == NULL) return;
    while(!st.empty()){
        auto it = st.top();
        st.pop();

        /*-> This is the part of pre*/
        /*-> Increment 1 to 2*/
        /*-> Put the left side of the tree*/
        if(it.second == 1){
            pre.push_back(it.first -> val);
            it.second++;
            st.push(it);
            if(it.first -> left != NULL){
                st.push({it.first->left, 1});
            }
        }
        /*-> This is the part of Inorder*/
        /*-> Increment 2 to 3*/
        /*-> Put the right side of the tree*/
        else if(it.second == 2){
            in.push_back(it.first -> val);
            it.second++;
            st.push(it);
            if(it.first -> right != NULL){
                st.push({it.first->right, 1});
            }
        }
        /*This is for post order*/
        /*Don't push it back again*/
        else{
            post.push_back(it.first -> val);
        }

    }
     // Print results
    cout << "Preorder: ";
    for(int x : pre) cout << x << " ";
    cout << "\nInorder: ";
    for(int x : in) cout << x << " ";
    cout << "\nPostorder: ";
    for(int x : post) cout << x << " ";
    cout << "\n";
}
int main(){
     /* Build tree
             1
            / \
           2   3
          / \   \
         4   5   6
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    preInPostTraversal(root);

   return 0;
}