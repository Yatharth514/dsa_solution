class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n =people.size();
        int l =0;
        int h =n-1;
        sort(people.begin(),people.end());
        int boats=0;
        while(l<=h)
        {
            if(l==h)
            {
                boats++;
                break;
            }
            else if (people[l]+people[h]<=limit)
            {
                boats++;
                l++;
                h--;
            }
            else
            {
                boats++;
                h--;
            }
        }
        return boats;
    }
};