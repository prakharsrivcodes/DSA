// optimal that i thoguht
#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int target)
{
    int n = arr.size();

    int low = 0;
    int high = n - 1;

    int ans = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target)
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

int upperBound(vector<int> &arr, int target)
{
    int n = arr.size();

    int low = 0;
    int high = n - 1;

    int ans = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target)
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

pair<int, int> firstLastOccurrence(vector<int> &arr, int target)
{
    int lb = lowerBound(arr, target);

    if (lb == arr.size() || arr[lb] != target)
        return {-1, -1};

    int ub = upperBound(arr, target);

    return {lb, ub - 1};
}

int main()
{
    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};

    pair<int, int> ans = firstLastOccurrence(arr, 8);

    cout << ans.first << " " << ans.second;
}
