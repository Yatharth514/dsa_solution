class Solution {
public:
    
    TreeNode* divide(vector<int>&nums,int low ,int high)
    {
        if(low>high)
        return NULL ;
        int mid=(low+high)/2;
        TreeNode*root=new TreeNode(nums[mid]);
        root->left=divide(nums,low,mid-1);
        root->right=divide(nums,mid+1,high);
        return root ;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root=NULL;
        root=divide(nums,0,nums.size()-1);
        return root;
        
    }
};