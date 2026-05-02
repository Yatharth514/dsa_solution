#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int d )
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node* buildBST(int n ,node* root)
{
    if(root==NULL)
    {
        root=new node(n);
    }
    else
    {
        if(n>=root->data)
        {
            root->right=buildBST(n,root->right);
        }
        else
        {
            root->left=buildBST(n,root->left);
        }
    }
    return root;
}
int minm(node*root)
{
    if(!root)
    {
        return -1;
    }
    if(root->left)
    return minm(root->left);

    return root->data;
}
int maxm(node* root)
{
    if(!root)
    {
        return -1;
    }
    if(root->right)
    return maxm(root->right);

    return root->data;
}
void levelOrderTraversal(node *root)
{
    if(root==NULL)
    return;
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
    
    cout<<"The BST for the given data :"<<endl;
    levelOrderTraversal(root);
    
    cout<<"The minimum of the BST : "<<minm(root)<<endl;
    cout<<"The maximum of the BST : "<<maxm(root)<<endl;


}