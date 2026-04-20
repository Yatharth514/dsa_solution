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
vector<int> TopView(node *root)
{   
    if(root==NULL)
    return {};
    queue<pair<node *, int>> q;
    map<int, int> mpp;
    q.push({root, 0});
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        node *cur = temp.first;
        int x = temp.second;
        if ((mpp.find(x) == mpp.end()))
        {
            mpp[x] = (cur->data);
        }
        if (cur->left)
        {
            q.push({cur->left, x - 1});
        }
        if (cur->right)
        {
            q.push({cur->right, x + 1});
        }
    }
    vector<int> ans;
    for (auto p : mpp)
    {
        ans.push_back(p.second);
    }
    return ans;
}
int main()
{
    node *root = NULL;
    cout << "Enter the data as -1 for not continuing ." << endl;
    root = buildTree(root);
    cout << "The Top View of the Tree : ";
    vector<int> ans = TopView(root);

    for (auto x : ans)
    {
        cout << x << " ";
    }

    cout << endl;
}