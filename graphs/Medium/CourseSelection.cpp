class Solution {
public:
   bool isCyclicdfs(unordered_map<int,vector<int>>&adjl,unordered_map<int,bool>&visited, unordered_map<int,bool>&dfs_visit,int i)
   {
    visited[i]=true;
    dfs_visit[i]=true;

    for(auto&it :adjl[i])
    {
        if(!visited[it])
        {
            if(isCyclicdfs(adjl,visited,dfs_visit,it))
            {
                return true;
            }
        }
        else if(dfs_visit[it])
        {
            return true;
        }
    }

    dfs_visit[i]=false;
    return false;
   }
    bool canFinish(int numCourses, vector<vector<int>>& num) {
        int n=num.size();
        unordered_map<int,vector<int>>adjl;
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfs_visit;
        for(int i =0;i<n;i++)
        {
            adjl[num[i][0]].push_back(num[i][1]);
        }

        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(isCyclicdfs(adjl,visited,dfs_visit,i))
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};