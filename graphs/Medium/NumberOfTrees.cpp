#include<bits/stdc++.h>
using  namespace std ;
void dfs(int i,unordered_map<int,bool>&visited,unordered_map<int,vector<int>>&adjl)
{
    visited[i]=true;
    for(auto &it:adjl[i])
    {
        if(!visited[it])
        {
            dfs(it,visited,adjl);
        }
    }
}
int main()
{
    int n ;
    cout<<"Enter the number of edges : ";
    cin>>n;
    vector<pair<int,int>>a;
    cout<<"Enter the edges  : ";
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        a.push_back({u,v});
    }
    int vertex ;
    cout<<"Enter the number of vertex : ";
    cin>>vertex;

    unordered_map<int,vector<int>>adjl;
    for(auto &it :a)
    {
        adjl[it.first].push_back(it.second);
        adjl[it.second].push_back(it.first);
    }
    unordered_map<int,bool>visited;

    int c=0;
    for(int i =0;i<vertex;i++)
    {
        if(!visited[i])
        {
            dfs(i,visited,adjl);
            c++;
        }
    }
    cout<<"The number of trees in the forest :"<<c;
    return 0;


}