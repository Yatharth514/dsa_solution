class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
         if(root == NULL)
        return {};
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>>c;
        vector<int>b;
        while(!q.empty())
        {
            TreeNode*temp=q.front();
            q.pop();
            if(temp==NULL)
            {
               c.push_back(b);
               b.clear();
               if(!q.empty())
               q.push(NULL);
            }
            else
            {
                b.push_back(temp->val);
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
        }
        reverse(c.begin(),c.end());
        return c;
        
    }
};