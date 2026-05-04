class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||root==p||root==q)
        return root;
        TreeNode* leftTree=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightTree=lowestCommonAncestor(root->right,p,q);
        if(leftTree!=NULL&&rightTree!=NULL)
        {
            return root;
        }
        else if(leftTree!=NULL&&rightTree==NULL)
        return leftTree;
        else if(leftTree==NULL&&rightTree!=NULL)
        return rightTree;
        else
        return NULL;
        
    }
};