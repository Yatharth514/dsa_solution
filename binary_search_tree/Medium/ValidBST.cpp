class Solution {
public:
    void inorder(TreeNode* root,vector<int>&ans)
    {
        if(!root)
        return ;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
        
    }
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        int n =ans.size();
        for(int i =1;i<n;i++)
        {
            if(ans[i]<=ans[i-1])
            return false;
        }
        return true;
        
    }
};