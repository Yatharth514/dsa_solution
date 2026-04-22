class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        return 0;
        queue<pair<TreeNode*,long long>>q;
        long long maxm=0;
        q.push({root,0});
        while(!q.empty())
        {    
            int curLvl=q.size();
            long long i =q.front().second;
            long long l=q.back().second;
            maxm=max(maxm,l-i+1);
            for(int j=0;j<curLvl;j++)
            {
                auto cur=q.front();
                q.pop();
                if(cur.first->left)
                q.push({cur.first->left,2*(cur.second-i)});
                if(cur.first->right)
                q.push({cur.first->right,2*(cur.second-i)+1});

            }
            
        }
        return maxm;

        
    }
};