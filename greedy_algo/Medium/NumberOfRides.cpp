class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n =landStartTime.size();
        int m =waterStartTime.size();

        int minml=INT_MAX;
        for(int i =0;i<n;i++)
        {
            minml=min(minml,landStartTime[i]+landDuration[i]);
        }
        int ansl=INT_MAX;
        for(int i=0;i<m;i++)
        {
            ansl=min(ansl,max(minml,waterStartTime[i])+waterDuration[i]);
        }

        int minmw=INT_MAX;

        for(int i =0;i<m;i++)
        {
            minmw=min(minmw,waterStartTime[i]+waterDuration[i]);
        }
        int answ=INT_MAX;
        for(int i=0;i<n;i++)
        {
            answ=min(answ,(max(minmw,landStartTime[i])+landDuration[i]));
        }

        
        return min(answ,ansl);
    }
};