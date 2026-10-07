class Solution {
  public:
  void dfs(int i ,unordered_map<int,vector<int>>&transpose,vector<int>&visited)
  {
      visited[i]=1;
      for(auto &it:transpose[i])
      {
          if(!visited[it])
          dfs(it,transpose,visited);
      }
  }
  void topo(int i,unordered_map<int,vector<int>>&adjl,vector<int>&visited,stack<int>&s)
  {
      visited[i]=1;
      for(auto &it:adjl[i])
      {
          if(!visited[it])
          {
              topo(it,adjl,visited,s);
          }
      }
      s.push(i);
      return ;
  }
    int countSCC(int V, vector<vector<int>> &edges) {
        // code here
        int n =edges.size();
        unordered_map<int,vector<int>>adjl;
        vector<int>visited(V,0);
        for(int i =0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adjl[u].push_back(v);
        }
        stack<int>s;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                topo(i,adjl , visited, s);
            }
        }
        unordered_map<int,vector<int>>transpose;
        for(int i =0;i<V;i++)
        {
            visited[i]=0;
            for(auto &it:adjl[i])
            {
                transpose[it].push_back(i);
            }
        }
        int count=0;
        while(!s.empty())
        {
            int top=s.top();
            s.pop();
            if(!visited[top])
            {
                count++;
                dfs(top,transpose,visited);
            }
        }
        return count;
        
    }
};