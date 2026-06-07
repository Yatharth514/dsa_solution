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
class Solution
{
public:
    TreeNode *createBinaryTree(vector<vector<int>> &description)
    {
        int n = description.size();
        unordered_map<int, TreeNode *> parent;
        unordered_set<int> childs;
        for (int i = 0; i < n; i++)
        {
            childs.insert(description[i][1]);
            if (parent.find(description[i][1]) == parent.end())
                parent[description[i][1]] = new TreeNode(description[i][1]);
            if (parent.find(description[i][0]) == parent.end())
                parent[description[i][0]] = new TreeNode(description[i][0]);

            if (description[i][2])
            {
                parent[description[i][0]]->left = parent[description[i][1]];
            }
            else
            {
                parent[description[i][0]]->right = parent[description[i][1]];
            }
        }
        TreeNode *root = NULL;
        for (int i = 0; i < n; i++)
        {
            if (childs.find(description[i][0]) == childs.end())
            {
                root = parent[description[i][0]];
                break;
            }
        }
        return root;
    }
};