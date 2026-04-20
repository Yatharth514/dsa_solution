class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        else if (p != NULL && q != NULL)
        {
            if ((p->val) == (q->val))
            {
                if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        return false;
    }
    void invert(TreeNode *root)
    {
        if (root == NULL)
            return;

        swap(root->left, root->right);
        invert(root->left);
        invert(root->right);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;

        if (root->left != NULL && root->right != NULL)
        {
            invert(root->right);
            return isSameTree(root->left, root->right);
        }
        if (root->right == NULL && root->left == NULL)
            return true;
        return false;
    }
};