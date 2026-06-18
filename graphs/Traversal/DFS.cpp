#include<bits/stdc++.h>
using namespace std;
void dfs(int i ,unordered_map<int,bool>&visited,unordered_map<int,vector<int>>&adjL,vector<int>&component)
{
    component.push_back(i);
    visited[i]=true;

    for(auto &it:adjL[i])
    {
        if(!visited[it])
        {
            dfs(it,visited,adjL,component);
        }
    }
}
vector<vector<int>>depth(int V,int E,vector<vector<int>>&edge)
{
    unordered_map<int,vector<int>>adjL;
    for(int i =0;i<edge.size();i++)
    {
        int u=edge[i][0];
        int v=edge[i][1];

        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    unordered_map<int,bool>visited;
    vector<vector<int>>ans;

    for(int i =0;i<V;i++)
    {
        if(!visited[i])
        {
            vector<int>component;
            dfs(i,visited,adjL,component);
            ans.push_back(component);
        }
    }

}
int main()
{

}

class Solution {
  public:
  void dfs(int i,vector<vector<int>>& adj,unordered_map<int,bool>&visited,vector<int>&ans)
  {
      ans.push_back(i);
      visited[i]=true;
      
      for(auto&it:adj[i])
      {
          if(!visited[it])
          {
              dfs(it,adj,visited,ans);
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n =adj.size();
        unordered_map<int,bool>visited;
        vector<int>ans;
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited,ans);
            }
        }
        return ans;
    }
};