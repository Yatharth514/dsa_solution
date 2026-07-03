class Solution {
  public:
  bool bfs( unordered_map<int,vector<int>>&adjl, unordered_map<int,bool>&visited,int i)
  {
      unordered_map<int,int>parent;
      parent[i]=-1;
      queue<int>q;
      q.push(i);
      visited[i]=true;
      
      while(!q.empty())
      {
          int front=q.front();
          q.pop();
          
          for(auto &it:adjl[front])
          {
              if(visited[it]&&it!=parent[front])
              {
                  return true ;
              }
              else if(!visited[it])
              {
                  visited[it]=true;
                  parent[it]=front;
                  q.push(it);
              }
          }
          
      }
      return false;
      
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        int n=edges.size();
        unordered_map<int,vector<int>>adjl;
        for(int i =0;i<n;i++)
        {
            adjl[edges[i][0]].push_back(edges[i][1]);
            adjl[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_map<int,bool>visited;
        
        for(int i =0;i<V;i++)
        {
            if(!visited[i])
            {
               if(bfs(adjl,visited,i))
               {
                   return true;
               }
            }
            
        }
        return false;
    }
};