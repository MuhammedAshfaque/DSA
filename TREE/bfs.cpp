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
vector<vector<int>> bfs(TreeNode* root){
    vector<vector<int>>ans;
    if(root == NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for( int i = 0; i < size; i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    vector<vector<int>> result = bfs(root);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
    }   
    return 0;
}