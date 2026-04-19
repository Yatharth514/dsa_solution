vector<vector<int>> verticalTraversal(TreeNode *root)
{
    queue<pair<TreeNode *, pair<int, int>>> q;
    map<int, map<int, multiset<int>>> nodes;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto temp = q.front();
        TreeNode *cur = temp.first;
        int x = temp.second.first;
        int y = temp.second.second;
        nodes[x][y].insert(cur->val);
        if (cur->left)
        {
            q.push({cur->left, {x - 1, y + 1}});
        }
        if (cur->right)
        {
            q.push({cur->right, {x + 1, y + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
