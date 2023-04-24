class Solution
{
public:
    int dominantPairs(int n, vector<int> &arr)
    {
        int half = n / 2;

        // sort in two halves
        sort(arr.begin(), arr.begin() + half);
        sort(arr.begin() + half, arr.end());

        // create two index pointer integers
        int i = 0, j = n / 2;
        int cnt = 0;

        while (i < half && j < n)
        {
            if (arr[i] >= 5 * arr[j])
            {
                // all in half - i range will satisfy
                cnt += (half - i);
                j++;
            }
            else
            {
                // go further
                i++;
            }
        }
        return cnt;
    }
};