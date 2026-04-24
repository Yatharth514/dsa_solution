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
bool isChildSum(node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    if (root->left != NULL && root->right != NULL)
    {
        if (root->data == (root->left)->data + (root->right)->data)
        {
            if (isChildSum(root->left) && isChildSum(root->right))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    if (root->left == NULL && root->right != NULL)
    {
        if (root->data == (root->right)->data)
        {
            return isChildSum(root->right);
        }
        else
        {
            return false;
        }
    }
    if (root->right == NULL && root->left != NULL)
    {
        if (root->data == (root->left)->data)
        {
            return isChildSum(root->left);
        }
        else
        {
            return false;
        }
    }
    return false;
}
int main()
{
    node *root = NULL;
    cout << "Enter the data as -1 for not continuing ." << endl;
    root = buildTree(root);
    cout << "Is this tree following child sum property ? " << isChildSum(root);
    return 0;
}