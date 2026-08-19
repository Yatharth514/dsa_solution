#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<int,vector<int>>adjl;
    unordered_map<int,bool>visited;
    int v;
    int u;
    vector<int>indegree;
    for(auto &it:adjl)
    {
        for(auto &p:it.second)
        {
            indegree[p]++;
        }
    } 
    queue<int>q;
    vector<int>ans;
    for(int i =0;i<v;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        ans.push_back(f);
        for(auto &it :adjl[f])
        {
           indegree[it]--;
           if(indegree[it]==0)
           q.push(it);
        }

    }

}