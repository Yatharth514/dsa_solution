class Solution
{
public:
    void right(TreeNode *root, vector<int> &ans, int lvl)
    {
        if (root == NULL)
            return;
        if (ans.size() == lvl)
        {
            ans.push_back(root->val);
        }
        lvl++;
        right(root->right, ans, lvl);
        right(root->left, ans, lvl);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == NULL)
            return {};

        vector<int> ans;
        int level = 0;
        right(root, ans, level);
        return ans;
    }
};