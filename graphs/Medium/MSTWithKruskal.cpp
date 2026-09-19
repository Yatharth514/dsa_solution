class cmp
{
    public:
    bool operator()(const vector<int>&a,const vector<int>&b)
    {
        return a[2]<b[2];
    }
};
class Solution {
  public:
  
  void makeSet(vector<int>&parent,vector<int>&rank,int n)
  {
      for(int i =0;i<n;i++)
      {
          parent[i]=i;
          rank[i]=0;
      }
      return;
  }
  int findParent(vector<int>&parent,int i)
  {
      if(parent[i]==i)
      return i;
      else
      {
        int k= findParent(parent,parent[i]);
        parent[i]=k;
        return k;
      }
  }
  void unionSet(int u,int v,vector<int>&parent,vector<int>&rank)
  {
      u=findParent(parent,u);
      v=findParent(parent,v);
      if(rank[u]<rank[v])
      {
          parent[u]=v;
      }
      else if(rank[v]<rank[u])
      {
          parent[v]=u;
      }
      else
      {
          parent[v]=u;
          rank[u]++;
      }
      
  }
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<int>rank(V);
        vector<int>parent(V);
        makeSet(parent,rank,V);
        cmp c;
        sort(edges.begin(),edges.end(),c);
        int n=edges.size();
        int minWt=0;
        for(int i =0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            if(findParent(parent,u)==findParent(parent,v))
            continue;
            else
            {
                minWt+=edges[i][2];
                unionSet(u,v,parent,rank);
            }
        }
        return minWt;
        
    }
};