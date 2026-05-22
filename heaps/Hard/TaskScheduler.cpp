class cmp
{
public:
    bool operator()(pair<int, char> &a, pair<int, char> &b)
    {
        if (a.first == b.first)
        {
            int ch1 = a.second - '0';
            int ch2 = b.second - '0';
            return ch1 < ch2;
        }
        return a.first < b.first;
    }
};

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        if (n == 0)
            return tasks.size();
        int k = tasks.size();
        unordered_map<char, int> mpp;
        unordered_map<char, int> allowed;
        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;
        for (int i = 0; i < k; i++)
        {

            mpp[tasks[i]]++;
            allowed[tasks[i]] = -1;
        }
        string ans = "";
        for (auto &it : mpp)
        {
            pq.push({it.second, it.first});
        }

        int i = 0;
        vector<pair<int, char>> temp;
        int exe = 1;
        while (i < k)
        {
            exe = 1;
            while (!pq.empty() && i < k)
            {
                int freq = pq.top().first;
                char ch = pq.top().second;
                pq.pop();
                if (allowed[ch] >= -1 && freq > 0)
                {
                    if (allowed[ch] == -1 || ans.length() - allowed[ch] >= n + 1)
                    {
                        ans += ch;
                        freq--;
                        if (freq > 0)
                        {
                            pq.push({freq, ch});
                        }
                        allowed[ch] = ans.length() - 1;
                        i++;
                        exe = 0;
                        break;
                    }
                    else
                    {
                        temp.push_back({freq, ch});
                    }
                }
            }
            if (pq.empty() && temp.size() > 0 && exe)
            {
                ans += '#';
                for (auto &j : temp)
                {
                    pq.push({j.first, j.second});
                }
                temp.clear();
            }
            if (temp.size() > 0)
            {
                for (auto &j : temp)
                {
                    pq.push({j.first, j.second});
                }
                temp.clear();
            }
        }

        return ans.length();
    }
};