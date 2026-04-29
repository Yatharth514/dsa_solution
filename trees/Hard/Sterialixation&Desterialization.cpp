/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "#";

        string s = "";
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp)
            {
                s += to_string(temp->val) + ",";

                q.push(temp->left);
                q.push(temp->right);
            }
            else
            {
                s += "#,";
            }
        }

        s.pop_back();
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data == "#")
            return NULL;
        vector<string> s;
        string temp = "";
        for (int i = 0; i < data.length(); i++)
        {
            if (data[i] == ',')
            {
                s.push_back(temp);
                temp = "";
            }
            else
            {
                temp += data[i];
            }
        }
        s.push_back(temp);
        if (s[0] == "#")
            return NULL;
        TreeNode *root = new TreeNode(stoi(s[0]));
        queue<TreeNode *> q;
        q.push(root);
        int i = 1;
        while ((!q.empty()) && i < s.size())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (s[i] != "#")
            {
                temp->left = new TreeNode(stoi(s[i]));
                q.push(temp->left);
            }
            i++;
            if (i < s.size() && s[i] != "#")
            {
                temp->right = new TreeNode(stoi(s[i]));
                q.push(temp->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));