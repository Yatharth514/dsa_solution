class Solution
{
public:
    TreeNode *make(vector<int> &postorder, vector<int> &inorder, unordered_map<int, int> &mpp, int inStart, int posEnd, int inEnd, int posStart)
    {
        if (inStart > inEnd || posStart < posEnd)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[posStart]);
        int index = mpp[postorder[posStart]];
        int rightSize = inEnd - index;
        root->right = make(postorder, inorder, mpp, index + 1, posStart - rightSize, inEnd, posStart - 1);
        root->left = make(postorder, inorder, mpp, inStart, posEnd, index - 1, posStart - rightSize - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> mpp;
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            mpp[inorder[i]] = i;
        }
        TreeNode *root = make(postorder, inorder, mpp, 0, 0, n - 1, n - 1);
        return root;
    }
};
// in this we have use inorder array to store their index .
// first we get the index of the parent root index by starting from the back of the postorder .
// then we divide the left and right side of the tree and build it recursively.