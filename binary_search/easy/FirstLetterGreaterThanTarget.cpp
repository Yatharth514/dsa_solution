class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int n = letters.size();
        int l = 0;
        int h = n - 1;
        int mid = 0;
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            if (l == h)
                break;
            else if (letters[mid] - target <= 0 && l != h)
                l = mid + 1;
            else
                h = mid;
        }
        if (letters[mid] <= target)
            return letters[0];
        else
            return letters[mid];
    }
};