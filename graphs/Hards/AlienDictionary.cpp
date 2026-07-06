class Solution
{
public:
    bool isCyclicdfs(int i, unordered_map<int, vector<int>> &adjl, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited)
    {
        visited[i] = true;
        dfsvisited[i] = true;

        for (auto &it : adjl[i])
        {
            if (!visited[it])
            {
                if (isCyclicdfs(it, adjl, visited, dfsvisited))
                    return true;
            }
            else if (dfsvisited[it])
                return true;
        }

        dfsvisited[i] = false;
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
    string findOrder(vector<string> &words)
    {
        // code here
        int n = words.size();
        unordered_map<int, vector<int>> adjl;
        unordered_map<int, bool> visited;
        unordered_map<int, bool> visited2;
        unordered_map<int, bool> dfsvisited;
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            string s = words[i];
            int m = words[i].length();
            for (int j = 0; j < m; j++)
            {
                st.insert(s[j] - 'a');
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            string s = words[i];
            string h = words[i + 1];

            int m = min(s.length(), h.length());
            int j = 0;
            while (j < m && s[j] == h[j])
                j++;
            if (j == m && s.length() > h.length())
                return "";

            adjl[s[j] - 'a'].push_back(h[j] - 'a');
        }

        for (int i : st)
        {
            if (!visited[i])
            {
                if (isCyclicdfs(i, adjl, visited, dfsvisited))
                    return "";
            }
        }
        stack<int> s;
        for (int i : st)
        {
            if (!visited2[i])
            {
                dfs(i, adjl, visited2, s);
            }
        }

        string ans;
        while (!s.empty())
        {
            ans += char(s.top() + 'a');
            s.pop();
        }
        return ans;
    }
};