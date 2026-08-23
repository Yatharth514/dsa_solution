class Solution {
public:
    bool sumGame(string num) {
        int n =num.length();
        int left_sum=0;
        int right_sum=0;
        int left_mark=0;
        int right_mark=0;

        for(int i =0;i<n;i++)
        {
            if(num[i]=='?')
            {
                if(i<n/2)
                left_mark++;
                else
                right_mark++;
            }
            else
            {
                if(i<n/2)
                left_sum+=num[i]-'0';
                else
                right_sum+=num[i]-'0';
            }
        }
        if((left_mark+right_mark)%2)
        return true;

       if(2 * (left_sum-right_sum) == 9 * (right_mark-left_mark))
    return false;

        return true;
    }
};
