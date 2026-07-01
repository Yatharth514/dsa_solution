class Solution {
public:
   void dfs(int sr,int sc,vector<vector<int>>& image,int color,vector<vector<bool>>&visited,int n ,int m)
   {
      visited[sr][sc]=true;
      int prev=image[sr][sc];
      image[sr][sc]=color;
      int row[]={1,-1,0,0};
      int col[]={0,0,1,-1};
      for(int i=0;i<4;i++)
      {
        int nr=sr+row[i];
        int nc=sc+col[i];
        if(nr>=0&&nr<n&&nc>=0&&nc<m&&prev==image[nr][nc]&&!visited[nr][nc])
        {
            dfs(nr,nc,image,color,visited,n,m);
        }
      }
      return ;
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        dfs(sr,sc,image,color,visited,n,m);
        return image;

        
    }
};