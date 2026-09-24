class Solution {
public:
void solve(vector<int>& candidates,int n,int k,vector<vector<int>>&b,vector<int>&c,int i,int sum,int prev)
{
    if(sum==k)
    {
        b.push_back(c);
        return ;
    }
    
    for(int j=i;j<n;j++)
    {
        if(candidates[j]>k-sum)
        return;
        if(prev==candidates[i])
    {
        solve(candidates,n,k,b,c,i+1,sum,prev);
        return;
    }
        else
        {
            sum+=candidates[j];
            c.push_back(candidates[j]);
            solve(candidates,n,k,b,c,j+1,sum,prev);
            if(c.size()>0)
            prev=c.back();
            sum-=candidates[j];
            c.pop_back();  
        }
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    int n =candidates.size();
    sort(candidates.begin(),candidates.end());
    vector<vector<int>>b;
    vector<int>c;
    solve(candidates,n,target,b,c,0,0,0);
    return b;
    }
};