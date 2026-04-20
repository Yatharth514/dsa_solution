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
void leftView(node *root, vector<int> &ans, int lvl)
{
    if (root == NULL)
        return;
    if (ans.size() == lvl)
    {
        ans.push_back(root->data);
    }
    lvl++;
    left(root->left, ans, lvl);
    left(root->right, ans, lvl);
}
int main()
{
    node *root = NULL;
    cout << "Enter the data as -1 for not continuing ." << endl;
    root = buildTree(root);
    cout << "The Left View of the Tree : ";
    vector<int> ans;
    leftView(root, ans, 0);
    for (int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}