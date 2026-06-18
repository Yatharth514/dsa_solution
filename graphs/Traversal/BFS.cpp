#include<bits/stdc++.h>
using namespace std;
void prepareAdjList(unordered_map<int,vector<int>>&adjL,vector<pair<int,int>>&edges)
{
    for(auto &it:edges)
    {
        adjL[it.first].push_back(it.second);
        adjL[it.second].push_back(it.first);
    }
}
void bfs(unordered_map<int,vector<int>>&adjL,unordered_map<int,bool>&visited,vector<int>&ans,int i)
{
    queue<int>q;
    q.push(i);
    visited[i]=1;

    while(!q.empty())
    {
       int front=q.front();
       q.pop();

       ans.push_back(front);
       for(auto&it:adjL[front])
       {
          if(!visited[it])
          {
            q.push(it);
            visited[it]=1;
          }
            
       }
    }
}
vector<int>BFS(int vertex,vector<pair<int,int>>edges)
{
    unordered_map<int,vector<int>>adjL;
    vector<int>ans;
    unordered_map<int,bool>visited;

    prepareAdjList(adjL,edges);
    
    //traverse all the components of the graph

    for (int i =0;i<vertex;i++)
    {
        if(!visited[i])
        {
            bfs(adjL,visited,ans,i);
        }
    }
}




class Solution {
  public:
    void BFS(vector<vector<int>> &adj,unordered_map<int,bool>&visited,vector<int>&ans,int i )
    {
        queue<int>q;
        q.push(i);
        visited[i]=true;
        
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            
            ans.push_back(f);
            for(auto&it:adj[f])
            {
                if(!visited[it])
                {
                    q.push(it);
                    visited[it]=true;
                }
                
            }
            
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        unordered_map<int,bool>visited;
        vector<int>ans;
        
        int n =adj.size();
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                BFS(adj,visited,ans,i);
            }
        }
        return ans;
        
    }
};