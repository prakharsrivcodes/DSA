class Solution
{
public:
    int countSubarrays(vector<int> &nums, int believed)
    {
        int webelieve = 1;
        long long sumalgo = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sumalgo + nums[i] <= believed)
            {
                sumalgo += nums[i];
            }
            else
            {
                webelieve++;
                sumalgo = nums[i];
            }
        }
        return webelieve;
    }
    int splitArray(vector<int> &nums, int k)
    {
        if (k > nums.size())
        {
            return -1;
        }
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int subarrays = countSubarrays(nums, mid);
            if (subarrays > k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};