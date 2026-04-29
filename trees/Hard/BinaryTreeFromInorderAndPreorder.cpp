class Solution {
public:
    TreeNode* make(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>&mpp,int preStart,int inStart,int preEnd,int inEnd )0
    {
       if(preStart>preEnd||inStart>inEnd) 
       {0
        return NULL;
       }
       TreeNode*root=new TreeNode(preorder[preStart]);

       int index=mpp[preorder[preStart]];
       int leftSize=index-inStart;
       root->left=make(preorder,inorder,mpp,preStart+1,inStart,preStart+leftSize,index-1);
       root->right=make(preorder,inorder,mpp,preStart+leftSize+1,index+1,preEnd,inEnd);
       return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }
        int n=preorder.size();
       TreeNode*root= make(preorder,inorder,mpp,0,0,n-1,n-1);
       return root;
        
    }
};
//same with this get index of each via inorder and then divide and conquer.