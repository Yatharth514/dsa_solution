#include<bits/stdc++.h>
using namespace std;
void dfs(int i ,unordered_map<int,vector<pair<int,int>>>&adjl,unordered_map<int,bool>&visited,stack<int>&s)
{
    visited[i]=true;
    for(auto &it:adjl[i])
    {
        if(!visited[it.first])
        dfs(it.first,adjl,visited,s);
    }
    s.push(i);
    return ;
}
void addedge(int u,int v,int w,unordered_map<int,vector<pair<int,int>>>&adjl)
{
    pair<int,int>p=make_pair(v,w);
    adjl[u].push_back(p);
}
int main()
{
    unordered_map<int,vector<pair<int,int>>>adjl;
    unordered_map<int,bool>visited;
    stack<int>s;
    int v;
    for(int i =0;i<v;i++)
    {
        if(!visited[i])
        dfs(i,adjl,visited,s);
    }
    int src=1;
    vector<int>dist(v,INT_MAX);

    dist[src]=0;

    while(!s.empty())
    {
        int f=s.top();
        
        if(dist[f]!=INT_MAX)
        {
            for(auto &it :adjl[f])
            {
                if(dist[it.first]>it.second+dist[f])
                dist[it.first]=it.second+dist[f];
            }
        }
        s.pop();

    }

}