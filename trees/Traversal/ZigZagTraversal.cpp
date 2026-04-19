class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};
        queue<TreeNode *> q;
        vector<int> b;
        vector<vector<int>> c;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                c.push_back(b);
                b.clear();
                if (!q.empty())
                    q.push(NULL);
            }
            else
            {
                b.push_back(temp->val);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
        for (int i = 0; i < c.size(); i++)
        {
            if (i % 2 == 1)
            {
                reverse(c[i].begin(), c[i].end());
            }
        }
        return c;
    }
};