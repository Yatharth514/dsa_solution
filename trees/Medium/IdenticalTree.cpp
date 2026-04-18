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
};