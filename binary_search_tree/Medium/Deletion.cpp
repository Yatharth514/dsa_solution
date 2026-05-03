#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* right;
    node* left;

    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node*deleteNode(node*root,int key)
{
    if(root==NULL)
        return NULL;

        if(root->data==key)
        {
            if(root->left==NULL&&root->right==NULL)
            return NULL;
            else if(root->left!=NULL&&root->right==NULL)
            {
                return root->left;
            }
            else if(root->left==NULL&&root->right!=NULL)
            {
               return root->right;
            }
            else
            {
                node* temp=root->right;
                while(temp->left)
                {
                    temp=temp->left;
                }
                root->data=temp->data;
                root->right=deleteNode(root->right,temp->data);
                return root;
            }

        }
        else if(key>root->data)
        {
            root->right=deleteNode(root->right,key);
        }
        else
        {
            root->left=deleteNode(root->left,key);
        }

        return root;
}
node*buildBST(int n ,node*root)
{
    if(!root)
    {
        root=new node(n);
    }
    else
    {
        if(n<root->data)
        root->left=buildBST(n,root->left);
        else
        root->right=buildBST(n,root->right);
    }
    return root;
}
int main()
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