class Solution {
public:
    bool isValidBST(TreeNode*root,int &sum,long long max_val,long long min_val)
    {
        if(!root)
        return true ;
       
        if(!(root->val>min_val)||!(root->val<max_val))
        return false;
        sum+=root->val;

        return isValidBST(root->left,sum,root->val,min_val)&&isValidBST(root->right,sum,max_val,root->val);



    }
    void Max_Sum_BST(TreeNode*root,int &max_sum)
    {
        if(!root)
        return ;
        int cur_sum=0;
        if(isValidBST(root,cur_sum,LLONG_MAX, LLONG_MIN))
        {
            max_sum=max(max_sum,cur_sum);
        }
        Max_Sum_BST(root->left,max_sum);
        Max_Sum_BST(root->right,max_sum);
    }
    int maxSumBST(TreeNode* root) {
        int max_sum=0;
        Max_Sum_BST(root,max_sum);
        return max_sum;
        
    }
};
//brute force 


