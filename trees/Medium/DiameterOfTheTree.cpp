class Solution {
public:
    int count(TreeNode*root)
    {
        if(root==NULL)
        return 0;
        int MaxLeft=count(root->left);
        int MaxRight=count(root->right);
        return max(MaxRight,MaxLeft)+1;
    }
    int diameter(TreeNode*root)
    {
        if(root==NULL)
        return 0;
        int leftpath=count(root->left);
        int rightpath=count(root->right);
        int dia=rightpath+leftpath;
        return max(diameter(root->left), max(diameter(root->right), dia));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        return 0;
        else
        return diameter(root);
        
    }
}; 
//This is the brute force to solve this question :taking the height of the left and right of the particular node and adding them and recursively calling for left and right tree asking them for maximum .
//Time Complexity:O(n*n)

//The Optimal Approach//

class Solution {
public:
    int diameter=0;
    int diameter_fast(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        int left=diameter_fast(root->left);
        int right=diameter_fast(root->right);
        diameter=max(diameter,left+right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        return 0;
        int k=diameter_fast(root);
        return diameter;
        
    }
};