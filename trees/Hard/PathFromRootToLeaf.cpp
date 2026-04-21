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
void path(node *root, vector<int> &ans, vector<int> &result)
{
    if (root == NULL)
        return;
    ans.push_back(root->data);
    if (root->left == NULL && root->right == NULL)
    {
        if (ans.size() >= result.size())
        {
            result = ans;
        }
    }
    if (root->left)
    {
        path(root->left, ans,result);
    }
    if (root->right)
    {
        path(root->right, ans,result);
    }
    ans.pop_back();
}
int main()
{
    node *root = NULL;
    cout << "Enter the data as -1 for not continuing ." << endl;
    root = buildTree(root);
    vector<int> ans;
    vector<int> result;
    path(root, ans, result);
    cout << "The Path from root to leaf is : ";
    for (int x : result)
    {
        cout << x << " ";
    }
    return 0;
}