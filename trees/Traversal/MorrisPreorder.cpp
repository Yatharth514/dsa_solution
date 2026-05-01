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
void preoder_morris(node* root)
{
    node* cur=root;
    while(cur!=NULL)
    {
        
        if(cur->left==NULL)
        {   
            cout<<cur->data<<" ";
            cur=cur->right;
        }
        else
        {
            node* IP=cur->left;
            while(IP->right!=NULL&&IP->right!=cur)
            {
                IP=IP->right;
            }
            if(IP->right==NULL)
            {  
                cout<<cur->data<<" ";
                IP->right=cur;
                cur=cur->left;
            }
            else
            {
                IP->right=NULL;

                cur=cur->right;
            }
        }
    }
    return ;
}
int main()
{
    node *root = NULL;
    cout << "Enter the data as -1 for not continuing ." << endl;
    root = buildTree(root);
    cout<<"The Morris Preorder Traversal : ";
    preoder_morris(root);
    return 0;
}