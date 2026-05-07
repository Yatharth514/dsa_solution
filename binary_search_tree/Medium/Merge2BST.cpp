/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    void inorder(Node *root, vector<int> &ans)
    {
        if (!root)
            return;

        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    void merge(vector<int> &ans, vector<int> &ans1, vector<int> &ans2)
    {
        int n = ans1.size();
        int m = ans2.size();

        int i = 0;
        int j = 0;
        while (i < n && j < m)
        {
            if (ans1[i] <= ans2[j])
            {
                ans.push_back(ans1[i]);
                i++;
            }
            else
            {
                ans.push_back(ans2[j]);
                j++;
            }
        }
        while (i < n)
        {
            ans.push_back(ans1[i]);
            i++;
        }
        while (j < m)
        {
            ans.push_back(ans2[j]);
            j++;
        }
        return;
    }

    vector<int> merge(Node *root1, Node *root2)
    {
        // code here
        if (!root1 && !root2)
            return {};
        vector<int> ans;
        vector<int> ans1;
        vector<int> ans2;

        inorder(root1, ans1);
        inorder(root2, ans2);

        merge(ans, ans1, ans2);

        return ans;
    }
};