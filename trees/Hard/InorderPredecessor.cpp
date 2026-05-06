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
node *inorder_predecessor(node *root, int key)
{
    node *cur = root;
    node *prev = NULL;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            if (cur->data == key)
                return prev;
            prev = cur;
            cur = cur->right;
        }
        else
        {
            node *IP = cur->left;
            while (IP->right != NULL && IP->right != cur)
            {
                IP = IP->right;
            }
            if (IP->right == NULL)
            {
                IP->right = cur;
                cur = cur->left;
            }
            else
            {
                IP->right = NULL;
                if (cur->data == key)
                    return prev;
                prev = cur;
                cur = cur->right;
            }
        }
    }
    return prev;
}
int main()
{
    node *root = NULL;
    cout << "Enter the data as -1 for not continuing ." << endl;
    root = buildTree(root);
    int key;
    cout << "Enter the number to take out the IP:" << endl;
    cin >> key;
    if (!inorder_predecessor(root, key))
    {
        cout << "There was no such number in the tree " << endl;
    }
    else
    {
        cout << "The IP of the " << key << " is : " << inorder_predecessor(root, key)->data << endl;
    }
    return 0;
}