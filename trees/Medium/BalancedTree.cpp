class Solution {
public:
    int count(TreeNode*root)
    {
        if(root==NULL)
        return 0;
        int MaxLeft=count(root->left);
        int MaxRight=count(root->right);
        return max(MaxRight,MaxLeft)+1;
    }
    bool isBalanced(TreeNode* root) {
         if(root==NULL)
         return true;
         if(abs(count(root->left)-count(root->right))<=1)
         {
           if(isBalanced(root->left)&&isBalanced(root->right))
           return true;
           else
           return false;
         }
         return false;   
    }
};