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
        this->right = NULL;
        this->left = NULL;
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
node *inorder_successor(node *root, int key)
{
    node *prev = NULL;
    node *cur = root;
    while (cur)
    {
        if (!cur->left)
        {
            if (prev && prev->data == key)
                return cur;
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
                if (prev && prev->data == key)
                    return cur;
                prev = cur;
                cur = cur->right;
            }
        }
    }

    return cur;
}
int main()
{
    node *root = NULL;
    cout << "Enter the data as -1 for not continuing ." << endl;
    root = buildTree(root);
    int key;
    cout << "Enter the number to take out the IS:" << endl;
    cin >> key;
    node* res=inorder_successor(root, key);
    if (!res)
        cout << "The number might be last in the sequence or does not even exit ." << endl;

    else
        cout << "The Inorder Successor of the " << key << " is : " << res->data << endl;
    return 0;
}
