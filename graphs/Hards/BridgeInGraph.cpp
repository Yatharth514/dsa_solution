#include<bits/stdc++.h>
using namespace std;
void dfs(int node,int parent,int &timer,vector<int>&disc,vector<int>&low,vector<vector<int>>&result,unordered_map<int,vector<int>>&adjl,vector<int>&visited)
{
    visited[node]=1;
    low[node]=timer;
    disc[node]=timer;
    timer++;
    for(auto &it:adjl[node])
    {
        if(it==parent)
        continue;
        if(!visited[it])
        {
            dfs(it,node,timer,disc,low,result,adjl,visited);
            low[node]=min(low[node],low[it]);
            //bridge case 
            if(low[it]>disc[node])
            {
                result.push_back({node,it});
            }
        }
        else
        {
            //back edge
            low[node]=min(disc[it],low[node]);
        }
    }

}
int main()
{}
vector<vector<int>> findBridges(vector<vector<int>>&edges,int V,int e)
{
    unordered_map<int,vector<int>>adjl;
    for(int i =0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }
    vector<int>disc(V);
    int timer=0;
    vector<int>low(V);
    int parent=-1;
    vector<int>visited(V,0);
    for(int i =0;i<V;i++)
    {
        disc[i]=-1;
        low[i]=-1;
    }
    vector<vector<int>>result;
    for(int i =0;i<V;i++)
    {
        if(!visited[i])
        {
            dfs(i,parent,timer,disc,low,result,adjl,visited);
        }
    }
    return result ;


}
