#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node *buildTree(node *root)
{
    int data;

    cout << "Enter the data : ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);
    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
int count(node*root)
{
    if(root==NULL)
    return 0;
    int leftTree=count(root->left);
    int rightTree=count(root->right);
    int c=leftTree+rightTree+1;
    return c;
}

int main()
{
    node *root = NULL;
    cout << "Enter the data as -1 for not continuing ." << endl;
    root = buildTree(root);
    cout<<"The number of the nodes in the binary tree : "<<count(root);
    return 0;

}

//The optimal approach 
class Solution {
public:
    int rightt(TreeNode*root)
    {
        int h;
        while(root)
        {
            h++;
            root=root->right;
    
        }
        return h;
    }

    int leftt(TreeNode*root)
    {
        int h;
        while(root)
        {
            h++;
            root=root->left;
        }
        return h;
    }
    int count(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        int leftTree=leftt(root);
        int rightTree=rightt(root);
        if(leftTree==rightTree)
        {
            return (1<<rightTree)-1;
        }
        else
        return 1+count(root->left)+count(root->right);
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
        return 0;
        else
        return count(root);

    }
};