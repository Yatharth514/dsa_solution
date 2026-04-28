class Solution
{
public:
    int amountOfTime(TreeNode *root, int start)
    {
        queue<TreeNode *> q;
        unordered_map<TreeNode *, TreeNode *> mpp;
        mpp[root] = NULL;
        q.push(root);
        q.push(NULL);
        TreeNode *target = NULL;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                if (temp->val == start)
                {
                    target = temp;
                }
                if (temp->left)
                {
                    mpp[temp->left] = temp;
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    mpp[temp->right] = temp;
                    q.push(temp->right);
                }
            }
        }
        int time = 0;
        if (target == NULL || (target->left == NULL && target->right == NULL && mpp[target] == NULL))
        {
            return time;
        }
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> travel;
        travel.push(target);
        travel.push(NULL);
        while (!travel.empty())
        {
            TreeNode *temp = travel.front();
            travel.pop();
            if (temp == NULL)
            {
                time++;
                if (!travel.empty())
                {
                    travel.push(NULL);
                }
            }
            else
            {
                if (visited[temp])
                    continue;
                visited[temp] = true;
                if (temp->left && !visited[temp->left])
                {
                    travel.push(temp->left);
                }
                if (temp->right && !visited[temp->right])
                {
                    travel.push(temp->right);
                }
                if (mpp[temp] && !visited[mpp[temp]])
                {
                    travel.push(mpp[temp]);
                }
            }
        }
        return time - 1;
    }
};