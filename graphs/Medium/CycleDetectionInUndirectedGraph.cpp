#include<bits/stdc++.h>
using namespace std;
int main()
{

}
bool isCyclic(int i ,int parent,unordered_map<int,vector<int>>&adjl,unordered_map<int,bool>&visited)
{
    visited[i]=true;
    for(auto &it:adjl[i])
    {
        if(!visited[it])
        {
            if(isCyclic(it,i,adjl,visited))
            return true;
        }
        else
        {
            if(it!=parent)
            return true;
        }

    }
    return false;
}