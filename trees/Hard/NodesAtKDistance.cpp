/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*>q;
        unordered_map<TreeNode*,TreeNode*>mpp;
        q.push(root);
        q.push(NULL);
        mpp[root]=NULL;
        while(!q.empty())
        {
            TreeNode*temp=q.front();
            q.pop();
            if(temp==NULL)
            {
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
            if(temp->left)
            {
                mpp[(temp->left)]=temp;
                q.push(temp->left);
            }
            if(temp->right)
            {   
                mpp[(temp->right)]=temp;
                q.push(temp->right);
            }
            }
        }
        int c=0;
        vector<int>ans;
        if(c==k)
        {
          ans.push_back(target->val);
          return ans;
        }
        queue<TreeNode*>tar;
        
        unordered_map<TreeNode*,bool>visit;

        tar.push(target);
        tar.push(NULL);
        while(!tar.empty())
        {
            TreeNode*temp=tar.front();
            tar.pop();
            if(temp==NULL)
            { 
                c++;
                if(c==k)
                {
                    while(!tar.empty())
                    {
                        int t=(tar.front())->val;
                        tar.pop();
                        ans.push_back(t);
                    }
                    return ans;
                }
                if(!tar.empty())
                {
                    tar.push(NULL);
                }
            }
            else
            {
             if(visit[temp])
             continue;
             visit[temp]=true;
            if(temp->left&&!visit[temp->left])
            {
                tar.push(temp->left);
            }
            if(temp->right&&!visit[temp->right])
            {
                tar.push(temp->right);
            }
            if(mpp[temp]&&!visit[mpp[temp]])
            {
                tar.push(mpp[temp]);
            }
            }
            
        }
        return ans;

        
    }
}; 