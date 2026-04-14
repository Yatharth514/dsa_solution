#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
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
void PreorderTraversal(node*root)
{
    if(root==NULL)
    return ;
    cout<<root->data<<" ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}
int main()
{
    node *root = NULL;
    cout << "Enter the data as -1 for not continuing ." << endl;
    root = buildTree(root);
    cout<<"The Preorder Traversal : "<<endl;
    PreorderTraversal(root);
    return 0;
}