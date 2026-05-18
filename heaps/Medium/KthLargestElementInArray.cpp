class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n =matrix.size();
        if(n==1&&k==1)
        return matrix[0][0];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minmh;
        for(int i=0;i<n;i++)
        {
            minmh.push({matrix[i][0],{i,0}});
        }
        for(int i =1;i<k;i++)
        {
            int first=minmh.top().second.first;
            int second=minmh.top().second.second;
            minmh.pop();
            if(second+1<n)
            {
                minmh.push({matrix[first][second+1],{first,second+1}});
            }

        }
        return minmh.top().first;


        
    }
};