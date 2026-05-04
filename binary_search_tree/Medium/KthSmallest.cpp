class Solution
{
public:
    void answer(TreeNode *root, int &k, int &res)
    {
        if (root == NULL)
            return;
        answer(root->left, k, res);
        k--;
        if (k == 0)
        {
            res = root->val;
        }
        answer(root->right, k, res);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int res = -1;
        answer(root, k, res);
        return res;
    }
};