#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;//n is the number of the nodes and whereas the m stands for the number of the edges
    vector<vector<int>>adjMat(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adjMat[u][v]=1;
        adjMat[v][u]=1;
    }//this is the matrix method for storing 

    vector<vector<int>>adjList(n+1);

    for(int i =0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        //adjList[v].push_back(u); only when undirected;

    }

    //if there is a weight graph then we will pair the neighbour to the weight
    
    return 0;



}