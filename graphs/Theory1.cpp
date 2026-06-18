#include<bits/stdc++.h>
using namespace std;
class graph
{
    public:
    unordered_map<int,vector<int>>adjL;

    void edge(int u,int v,bool direction)
    {
        adjL[u].push_back(v);
        if(!direction)
        {
            adjL[v].push_back(u);
        }

    }

    void print()
    {
        for(auto &it:adjL)
        {
            cout<<it.first<<"->";
            for(auto &in:it.second)
            {
                cout<<in<<",";
            }
            cout<<endl;
        }
    }
};
int main()
{
    int n ;
    cout<<"Enter the number of the nodes : ";
    cin>>n;

    int m ;
    cout<<"Enter the number of the edges : ";
    cin>>m;

    int direction ;
    cout<<"Whether it is directed or not? : ";
    cin>>direction;

    graph g;

    for(int i =0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g.edge(u,v,direction);
    }

    g.print();
    return 0;
    

}