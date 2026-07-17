#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMin(vector<int>& arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = INT_MAX;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        // Left half is sorted
        if(arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        // Right half is sorted
        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {4,5,6,7,0,1,2};

    cout << findMin(arr);

    return 0;
}