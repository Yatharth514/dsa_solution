#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node*left;
    node*right;

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
void path_sum(node*root,int sum ,pair<int,int>&max_sum,int c)
{
    if(root==NULL)
    {
        return ;
    }
    sum=sum+root->data;
    if(root->left==NULL&&root->right==NULL)
    {
        if(max_sum.second<c||(c==max_sum.second&&max_sum.first<sum))
        {
        max_sum.second=c;
        max_sum.first=sum;
        }
    }
    path_sum(root->left,sum,max_sum,c+1);
    path_sum(root->right,sum,max_sum,c+1);
    
}
int main()
{
    node *root = NULL;
    cout << "Enter the data as -1 for not continuing ." << endl;
    root = buildTree(root);
    if(root==NULL)
    {
    cout<<"The binary Tree is empty";
    return 0;
    }
    pair<int,int>max_sum;
    max_sum = make_pair(INT_MIN, 1);
    path_sum(root,0,max_sum,1);
    cout<<"The sum of the longest path :"<<max_sum.first;
    return 0;

}