class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL || root->val == p->val || root->val == q->val)
            return root;
        TreeNode *lefttree = lowestCommonAncestor(root->left, p, q);
        TreeNode *righttree = lowestCommonAncestor(root->right, p, q);
        if (lefttree != NULL && righttree != NULL)
            return root;
        if (lefttree != NULL && righttree == NULL)
            return lefttree;
        if (righttree != NULL && lefttree == NULL)
            return righttree;
        else
        {
            return NULL;
        }
    }
};