class Solution
{
public:
    int minCost(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0 || n == 1)
            return 0;
        if (n == 2)
            return arr[0] + arr[1];

        priority_queue<int, vector<int>, greater<int>> minm;
        for (int i = 0; i < n; i++)
        {
            minm.push(arr[i]);
        }
        int sum = 0;
        while (!minm.empty() && minm.size() > 1)
        {
            int first = minm.top();
            minm.pop();
            int second = minm.top();
            minm.pop();
            int sum2 = first + second;
            sum += sum2;
            minm.push(sum2);
        }
        return sum;
    }
};