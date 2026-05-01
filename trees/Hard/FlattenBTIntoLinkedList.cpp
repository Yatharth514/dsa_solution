class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur=root;
        while(cur!=NULL)
        {
            if(cur->left)
            {
                TreeNode* IP=cur->left;
                while(IP->right!=NULL)
                {
                    IP=IP->right;
                }
                IP->right=cur->right;
                cur->right=cur->left;
                cur->left=NULL;
            }
            cur=cur->right;
        }
        return ;

    }
};