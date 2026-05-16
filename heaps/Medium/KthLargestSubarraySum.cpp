#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n ;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements : "<<endl;
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the kth number largest which you want : ";
    cin>>k;
    if(k>n)
    {
        cout<<"Invalid input !"<<endl;
        return 0;
    }
    priority_queue<int>maxh;
    for(int i =0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            maxh.push(sum);
        }
    }
    for(int i =1;i<k;i++)
    {
        maxh.pop();
    }
    cout<<"Kth Largest Subarray Sum is : "<<maxh.top();
    return 0;
}
