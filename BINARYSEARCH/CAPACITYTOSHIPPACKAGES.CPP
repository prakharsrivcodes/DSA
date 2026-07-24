#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>& weights, int capacity)
{
    int days = 1;
    int currentLoad = 0;

    for(int i = 0; i < weights.size(); i++)
    {
        if(currentLoad + weights[i] <= capacity)
        {
            currentLoad += weights[i];
        }
        else
        {
            days++;
            currentLoad = weights[i];
        }
    }

    return days;
}

int shipWithinDays(vector<int>& weights, int days)
{
    int low = weights[0];
    int high = 0;

    for(int i = 0; i < weights.size(); i++)
    {
        low = max(low, weights[i]);
        high += weights[i];
    }

    int ans = high;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        int daysNeeded = helper(weights, mid);

        if(daysNeeded <= days)
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
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    cout << shipWithinDays(weights, days);

    return 0;
}