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
void makeChildSum(node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    if (root->left != NULL && root->right != NULL)
    {
        if (root->data > (root->left)->data + (root->right)->data)
        {
            (root->left)->data = root->data;
            (root->right)->data = root->data;
            makeChildSum(root->left);
            makeChildSum(root->right);
            if (root->data < (root->left)->data + (root->right)->data)
            {
                root->data = (root->left)->data + (root->right)->data;
                return;
            }
        }
        if (root->data == (root->left)->data + (root->right)->data)
        {
            makeChildSum(root->left);
            makeChildSum(root->right);
            if (root->data < (root->left)->data + (root->right)->data)
            {
                root->data = (root->left)->data + (root->right)->data;
                return;
            }
        }
        if (root->data < (root->left)->data + (root->right)->data)
        {
            root->data = (root->left)->data + (root->right)->data;
            makeChildSum(root->left);
            makeChildSum(root->right);
            if (root->data < (root->left)->data + (root->right)->data)
            {
                root->data = (root->left)->data + (root->right)->data;
                return;
            }
        }
    }
    if (root->left!=NULL&&root->right==NULL)
    {
        if (root->data == (root->left)->data)
        {
            makeChildSum(root->left);
            if (root->data < (root->left)->data)
            {
                root->data = (root->left)->data;
                return;
            }
        }
        if (root->data > (root->left)->data)
        {
            (root->left)->data = root->data;
            makeChildSum(root->left);
            if (root->data < (root->left)->data)
            {
                root->data = (root->left)->data;
                return;
            }
        }
        if (root->data < (root->left)->data)
        {
            root->data = (root->left)->data;
            makeChildSum(root->left);
            if (root->data < (root->left)->data)
            {
                root->data = (root->left)->data;
                return;
            }
        }
    }
    if (root->right!=NULL&&root->left==NULL)
    {
        if (root->data == (root->right)->data)
        {
            makeChildSum(root->right);
            if (root->data < (root->right)->data)
            {
                root->data = (root->right)->data;
                return;
            }
        }
        if (root->data > (root->right)->data)
        {
            (root->right)->data = root->data;
            makeChildSum(root->right);
            if (root->data < (root->right)->data)
            {
                root->data = (root->right)->data;
                return;
            }
            if (root->data < (root->right)->data)
            {
                root->data = (root->right)->data;
                makeChildSum(root->right);
                if (root->data < (root->right)->data)
                {
                    root->data = (root->right)->data;
                    return;
                }
            }
        }
    }
    return;
}
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node *root = NULL;
    cout << "Enter the data as -1 for not continuing ." << endl;
    root = buildTree(root);
    makeChildSum(root);
    levelOrderTraversal(root);

}
//This is the brute force with complicated checking and use of nested if .