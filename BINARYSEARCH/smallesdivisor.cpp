#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>& nums, int divisor)
{
    int sum = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        sum += (nums[i] + divisor - 1) / divisor;
    }

    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold)
{
    int low = 1;
    int high = nums[0];

    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] > high)
            high = nums[i];
    }

    int ans = high;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        int sum = helper(nums, mid);

        if(sum <= threshold)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    cout << smallestDivisor(nums, threshold);

    return 0;
}