class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr1;
        vector<int> arr2;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                arr1.push_back(nums[i]);
            else if (i == 1)
                arr2.push_back(nums[i]);
            else
            {
                int k = arr1.size();
                int m = arr2.size();
                if (arr1[k - 1] > arr2[m - 1])
                    arr1.push_back(nums[i]);
                else
                    arr2.push_back(nums[i]);
            }
        }

        for (int i = 0; i < arr1.size(); i++)
            res.push_back(arr1[i]);
        for (int i = 0; i < arr2.size(); i++)
            res.push_back(arr2[i]);
        return res;
    }
};