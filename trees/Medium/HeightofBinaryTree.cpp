class Solution {
public:
    
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        return 0;
        int c=0;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
           TreeNode*temp=q.front();
           q.pop();
           if(temp==NULL)
           {
            c++;
            if(!q.empty())
            q.push(NULL);
           }
           else
           {
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
           }

        }
        return c;
        
    }
};

//This is the brute force approach comprimising with the space .

//The Optimal Solution

int height(TreeNode* root)
{
    if(root==NULL)
    return 0;

    int LeftHeight=height(root->left);
    int RightHeight=height(root->right);

    return max(LeftHeight,RightHeight)+1;
}
