#include<bits/stdc++.h>
using namespace std;
int first_search(int l,int h,vector<int>&b,int target)
{
    int n =b.size();
    if(b[n-1]<target)
    return -1;
    int mid=0;
    while(l<=h)
    {
        mid=l+(h-l)/2;
        if(b[mid]<target)
        l=mid+1;
        else
        h=mid-1;
    }
    if(b[h+1]>=target)
    return h+1;
    else
    return -1;
}
int second_search(int l,int h,vector<int>&b,int target)
{
    int n =b.size();
    if(b[l]>target)
    return -1;
 
    int mid=0;
    while(l<=h)
    {
        mid=l+(h-l)/2;
        if(b[mid]>target)
        h=mid-1;
        else
        l=mid+1;
    }
    return l-1;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(n);
    vector<int>b(m);
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i =0;i<m;i++)
    {
        cin>>b[i];
    }
    int ans=0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int l=0;
    for(int i =0;i<n;i++)
    {
        int first=a[i]-k;
        int second=a[i]+k;
        int index=first_search(l,m-1,b,first);
        int index2=second_search(l,m-1,b,second);
        if(index!=-1&&index2!=-1)
        {
            if(l<m&&index>=l&&b[index]<=second)
            {
                ans++;
                l=index+1;
            }
            
        }
        else if(index==-1&&index2!=-1)
        {
            if(l<m&&b[index2]>=a[i])
            {
            ans++;
            l=index2+1;
            }
        }
        // cout<<a[i]<<endl;
        // cout<<index<<endl;
        // cout<<index2<<endl;
        // cout<<ans<<endl;
        // cout<<l<<endl;
        // cout<<endl;
 
 
    }
    cout<<ans;
 
 
    return 0;
}