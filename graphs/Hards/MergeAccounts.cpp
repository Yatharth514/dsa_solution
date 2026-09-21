class Solution
{
public:
    void unionSet(string email1, string email2, unordered_map<string, string> &parent, unordered_map<string, int> &ranks)
    {
        string pu = findParent(email1, parent);
        string pv = findParent(email2, parent);
        if (ranks[pu] < ranks[pv])
        {
            parent[pu] = pv;
        }
        else if (ranks[pv] < ranks[pu])
            parent[pv] = pu;
        else
        {
            parent[pv] = pu;
            ranks[pu]++;
        }
    }
    string findParent(string email, unordered_map<string, string> &parent)
    {
        if (email == parent[email])
            return email;
        else
        {
            string str = findParent(parent[email], parent);
            parent[email] = str;
            return str;
        }
    }
    void makeSet(vector<vector<string>> &accounts, unordered_map<string, string> &parent, unordered_map<string, int> &ranks, int n)
    {
        for (int i = 0; i < n; i++)
        {
            int m = accounts[i].size();
            for (int j = 1; j < m; j++)
            {
                parent[accounts[i][j]] = accounts[i][j];
                ranks[accounts[i][j]] = 0;
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, string> parent;
        unordered_map<string, int> ranks;
        int n = accounts.size();
        makeSet(accounts, parent, ranks, n);
        unordered_map<string, string> emailToName;
        for (int i = 0; i < n; i++)
        {
            int m = accounts[i].size();
            for (int j = 1; j < m; j++)
            {
                emailToName[accounts[i][j]] = accounts[i][0];
            }
        }
        for (int i = 0; i < n; i++)
        {
            int m = accounts[i].size();
            for (int j = 2; j < m; j++)
            {

                string email1 = accounts[i][1];
                string email2 = accounts[i][j];
                if (findParent(email1, parent) != findParent(email2, parent))
                {
                    unionSet(email1, email2, parent, ranks);
                }
            }
        }
        unordered_map<string, vector<string>> child;
        for (auto &it : parent)
        {
            string email = it.first;
            string emailp = findParent(email, parent);
            child[emailp].push_back(email);
        }
        vector<vector<string>> ans;
        for (auto &it : child)
        {
            string pe = it.first;
            vector<string> email = it.second;
            sort(email.begin(), email.end());
            vector<string> acc;
            acc.push_back(emailToName[pe]);
            for (auto &p : email)
                acc.push_back(p);
            ans.push_back(acc);
        }
        return ans;
    }
};