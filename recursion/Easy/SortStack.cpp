#include<bits/stdc++.h>
using namespace std;
void replacement(stack<int>&s,int k)
{
    if(s.empty()||s.top()<=k)
    {
        s.push(k);
        return ;
    }
    int t=s.top();
    s.pop();
    replacement(s,k);
    s.push(t);
}
void sort_stack(stack<int>&s)
{
    if(s.empty())
    return ;
    int temp=s.top();
    s.pop();
    sort_stack(s);
    replacement(s,temp);

}
int main()
{
    int n ;
    cout<<"Enter the number of the elements you want to insert in the stack : ";
    cin>>n;
    int data;
    stack<int>s;
    for(int i =0;i<n;i++)
    {
        cout<<"Enter the data : ";
        cin>>data;
        s.push(data);
    }
    sort_stack(s);
    cout<<"Sorted stack : ";
    while(!s.empty())
    {   

        int x=s.top();
        s.pop();
        cout<<x<<" ";
    }
    return 0;
}