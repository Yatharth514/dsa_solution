#include<bits/stdc++.h>
using namespace std;
void bfs(int i ,vector<int>&visited,vector<int>&parent,unordered_map<int,vector<int>>&adjl)
{
    parent[i]=-1;
    visited[i]=1;
    queue<int>q;
    q.push(i);
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        for(auto &it:adjl[i])
        {
            if(!visited[it])
            {
                q.push(it);
                parent[it]=i;
                visited[it]=1;
            }

        }
    }
}
int main()
{
    unordered_map<int,vector<int>>adjl;
    vector<int>parent;
    vector<int>visited;
    int n ;
    for(int i =0;i<n;i++)
    {
        if(!visited[i])
        bfs(i,visited,parent,adjl);
    }
    int s,d;
    int cur=d;
    vector<int>ans;
    ans.push_back(d);
    while(cur!=s)
    {
        cur=parent[cur];
        ans.push_back(cur);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}