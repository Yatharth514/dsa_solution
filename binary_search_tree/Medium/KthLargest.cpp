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
node* buildBST(int n ,node*root)
{
    if(!root)
    {
        root=new node(n);
    }
    else
    {
        if(n<root->data)
        {
            root->left=buildBST(n,root->left);
        }
        else
        {
            root->right=buildBST(n,root->right);
        }
    }
    return root;
}
void answer(node *root, int &k, int &res)
    {
        if (root == NULL)
            return;
        answer(root->right, k, res);
        k--;
        if (k == 0)
        {
            res = root->data;
        }
        answer(root->left, k, res);
    }
    int kthSmallest(node *root, int k)
    {
        int res = -1;
        answer(root, k, res);
        return res;
    }

int main ()
{
    node*root=NULL;
    int n ;
    cout<<"Enter the number of integers you want to enter in the BST :";
    cin>>n;
    vector<int>a(n);
    cout<<"Enter the data you want to enter "<<endl;
    for(int i=0;i<n;i++)
    {   
        cout<<"Enter the data : ";
        cin>>a[i];
    }

    cout<<"Creating the BST ...."<<endl;

    for(int i=0;i<n;i++)
    {
        root=buildBST(a[i],root);
    }

}