class Solution {
public:
    int max_sum=INT_MIN;
    int maxm(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        int left_max=maxm(root->left);
        int right_max=maxm(root->right);
        left_max = max(0, left_max);
        right_max = max(0, right_max);
        if(max_sum<left_max+right_max+root->val)
        max_sum=left_max+right_max+root->val;

        return max(left_max,max(right_max,0))+root->val;

    }
    int maxPathSum(TreeNode* root) {
        maxm(root);
        return max_sum;
        
    }

};