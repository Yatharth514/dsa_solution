/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode*cur=root;
        TreeNode*prev=NULL;
        TreeNode*first=NULL;
        TreeNode*second=NULL;
        while(cur)
        {
            if(!cur->left)
            {
                if(prev&&(cur->val)<prev->val)
                {
                    if(!first)
                    {
                    first=prev;
                    second=cur;
                    }
                    else
                    second=cur;
                }
                prev=cur;
                cur=cur->right;
            }
            else
            {
                TreeNode*IP=cur->left;
                while(IP->right&&IP->right!=cur)
                {
                    IP=IP->right;
                }
                if(!IP->right)
                {
                    IP->right=cur;
                    cur=cur->left;
                }
                else
                {
                   IP->right=NULL; 
                if(prev&&(cur->val)<prev->val)
                {
                    if(!first)
                    {
                    first=prev;
                    second=cur;
                    }
                    else
                    second=cur;
                }
                prev=cur;
                cur=cur->right;
                }
            }
        }
        swap(first->val,second->val);
        return ;
        
    }
};