#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n ;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int>a(n);
    cout<<"Enter the elements in the array : ";
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    int first =a[0];
    int second=0;
    bool change =false;

    for(int i =1;i<n;i++)
    {
        if(a[i]>first)
        {
            int k=first;
            first=a[i];
            change=true;
            second=k;

        }
        else if( a[i]<first&&((!change)||a[i]>second))
        {
            change=true;
            second=a[i];
        }

    }
    if(change)
    {
        cout<<second;
        return 0;
    }
    cout<<-1;
    return 0;

}