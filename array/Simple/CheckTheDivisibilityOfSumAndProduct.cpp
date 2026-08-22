class Solution
{
public:
    bool checkDivisibility(int n)
    {
        int s = 0;
        int p = 1;
        int num = n;
        while (num != 0)
        {
            int d = num % 10;
            s = s + d;
            num /= 10;
        }
        num = n;
        while (num != 0)
        {
            int d = num % 10;
            p = p * d;
            num /= 10;
        }

        return (n % (s + p) == 0);
    }
};