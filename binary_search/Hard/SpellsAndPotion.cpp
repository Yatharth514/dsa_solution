class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n =spells.size();
        int m=potions.size();
        vector<int>ans;
        
        
        if(m==1)
        {
           for(int i =0;i<n;i++)
           {
              if(spells[i]*potions[0]>=success)
              ans.push_back(1);
           }
           return ans;
        }
        sort(potions.begin(),potions.end());
        
        for(int i =0;i<n;i++)
        {
            int spell=spells[i];
            int l=0;
            int h=m-1;
            int mid=0;
            long long  target= 0;
            if(success%spell==0)
            {
                target=success/spell;
            }
            else
            target=(success/spell) +1;
            if(spell==1)
            {
                if(potions[m-1]<success)
                {
                    ans.push_back(0);
                    continue;
                }
            }

            while(l<h)
            {
                mid=l+(h-l)/2;
                if((long long)potions[mid]<target)
                l=mid+1;
                else 
                h=mid;
            }
            cout<<h<<endl;
            if(h==0)
            ans.push_back(m);
            else if(h==m-1)
            {
                if((long long) potions[h]<target)
                ans.push_back(0);
                else
                ans.push_back(1);
            }
            else
            {
                ans.push_back(m-h);
            }

           
        }
        return ans;
    }
};