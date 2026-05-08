class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> ans;
        inorder(root, ans);
        int n = ans.size();
        if (n < 2)
            return false;
        int l = 0;
        int r = n - 1;
        while (l < r)
        {
            int sum = ans[l] + ans[r];
            if (sum == k)
                return true;
            else if (sum > k)
                r--;
            else
                l++;
        }
        return false;
    }
};
