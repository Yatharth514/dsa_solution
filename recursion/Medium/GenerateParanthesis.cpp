#include<bits/stdc++.h>
using namespace std;
void make(int n,string s ,vector<string>&str,int open ,int close)
{   
    int num=s.length();
    if(num==2*n)
    {
        str.push_back(s);
        return ;
    }
    if(open<n)
    {
        make(n,s+'(',str,open+1,close);

    }
    if(close<open)
    {
        make(n,s+')',str,open,close+1);
    }
    
}
int main()
{
    int n ;
    cout<<"Enter the length of paranthesis : ";
    cin>>n;
    vector<string>str;
    string s="";
    int open =0;
    int close =0;
    make(n,s,str,open,close);
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    return 0;

}