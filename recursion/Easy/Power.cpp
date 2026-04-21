class Solution {
public:
    double pow(double x, long long k)
    {
        if(k==0)
        return 1;
         
         if(k%2==0)
         {
            return pow(x*x,k/2);
         }
         else
         {
            return x*pow(x,k-1);
         }
    }

    double myPow(double x, int n) {
        long long k=n;
        if(k>=0)
        {
            return pow(x,k);
        }
        else
        {
            return 1.0/pow(x,(k*-1));
        }
        
    }
};