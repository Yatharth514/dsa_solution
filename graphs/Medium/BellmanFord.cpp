class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V,1e8);
        dist[src]=0;
        for(int i =1;i<=V-1;i++)
        {
            for(int j=0;j<edges.size();j++)
            {
                int u=edges[j][0];
                int v=edges[j][1];
                int w=edges[j][2];
                
                if(dist[u]!=1e8&&(dist[u]+w<dist[v]))
                dist[v]=dist[u]+w;
            }
        }
        int flag=0;
        for(int j=0;j<edges.size();j++)
            {
                int u=edges[j][0];
                int v=edges[j][1];
                int w=edges[j][2];
                
                if(dist[u]!=1e8&&(dist[u]+w<dist[v]))
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
            return {-1};
            else
            return dist;
        
    }
};
