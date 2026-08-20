#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<int,vector<int>>adjl;
    vector<int>indegree;
    for(auto &it:adjl)
    {
        for(auto &p:it.second)
        indegree[p]++;
    }

    queue<int>q;
    for(int i =0;i<v;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    int c=0;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        c++;
        for(auto &it:adjl[f])
        {
            indegree[it]--;
            if(indegree[it]==0)
            q.push(it);
        }
        
    }
    if(c==n)
    return false; //a valid topological order will have n nodes just like in graph
    else 
    return true;
}
