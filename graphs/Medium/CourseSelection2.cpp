class Solution
{
public:
    bool isCyclicdfs(unordered_map<int, vector<int>> &adjl, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfs_visit, int i)
    {
        visited[i] = true;
        dfs_visit[i] = true;

        for (auto &it : adjl[i])
        {
            if (!visited[it])
            {
                if (isCyclicdfs(adjl, visited, dfs_visit, it))
                {
                    return true;
                }
            }
            else if (dfs_visit[it])
            {
                return true;
            }
        }

        dfs_visit[i] = false;
        return false;
    }
    void dfs(int i, unordered_map<int, vector<int>> &adjl, unordered_map<int, bool> &visited2, stack<int> &s)
    {
        visited2[i] = true;
        for (auto &it : adjl[i])
        {
            if (!visited2[it])
            {
                dfs(it, adjl, visited2, s);
            }
        }
        s.push(i);
        return;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &nums)
    {
        if (numCourses == 1)
            return {0};

        unordered_map<int, vector<int>> adjl;
        unordered_map<int, bool> visited;
        unordered_map<int, bool> visited2;
        unordered_map<int, bool> dfs_visit;
        stack<int> s;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            adjl[nums[i][1]].push_back(nums[i][0]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                if (isCyclicdfs(adjl, visited, dfs_visit, i))
                {
                    return {};
                }
            }
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited2[i])
            {
                dfs(i, adjl, visited2, s);
            }
        }
        vector<int> ans;
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};