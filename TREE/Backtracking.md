           1
         /   \
       2       3
        \     /  \  
         6   4    5     
                 /  \  
                6    7 
TreeNode* lowestCommonAncestor(TreeNode* root(1), TreeNode* p(7), TreeNode* q(8)) {
        if(root == NULL || root == p || root == q){
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root -> left p, q)e (*);
        TreeNode *right = lowestCommonAncestor(root -> right p, q)e;
        if(left == NULL){ return right;}  
        else if(right == NULL){ return left;}   
}

           1
         /   \
        2     5
      /  \     \  
     3    4     6     
               /  
              7   
TreeNode* prev = NULL;
void flatten(TreeNode* root)1 {
    if(root == NULL) return;
    flatten(root -> right)e;
    flatten(root -> left);
    root->right = prev;
    root->left = NULL;
    prev = root;
}
5->6->7->NULL



