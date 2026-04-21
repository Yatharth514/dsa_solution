class Solution {
public:
    const long long MOD=1e9+7;
    long long pow(long long  x,long long k)
    {
        if(k==0)
        return 1;
        if(k%2==0)
        return (pow((x*x)%MOD,k/2));
        else
        return (x%MOD*pow(x,k-1))%MOD;
    }
    int countGoodNumbers(long long n) {
        long long e_pow=n/2;
        long long o_pow=(n+1)/2;
        long long ans=(pow(5,o_pow)*pow(4,e_pow))%MOD;
        return ans;

    }
};