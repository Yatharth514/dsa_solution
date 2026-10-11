class Solution
{
public:
    int countOnes(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        int l = 0;
        int h = n - 1;
        if (arr[0] == arr[n - 1] && arr[0] == 1)
            return n;
        int mid = 0;

        while (l <= h)
        {
            mid = l + (h - l) / 2;
            if (arr[mid] < 1)
                h = mid - 1;
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};