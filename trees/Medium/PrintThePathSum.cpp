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

int path(node*root,int sum ,vector<int>&ans,vector<int>&result,int max_sum)
{
   if(root==NULL)
   return 0 ;
   int left_path=path(root->left,sum,ans,result,max_sum);
   int right_path=path(root->right,sum,ans,result,max_sum);
   left_path=max(0,left_path);
   right_path=max(0,right_path);
   if(max_sum<root->data+left_path+right_path)
   {
    ans.push_back(root->data);
   }


   
}