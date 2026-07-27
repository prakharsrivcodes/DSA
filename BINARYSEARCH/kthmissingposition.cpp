#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        // Har element ke liye check karenge
        for (int i = 0; i < arr.size(); i++)
        {
            // Agar array ka element hamare current k se chhota ya barabar hai,
            // toh yeh element missing number ki position ko 1 step aage push karega.
            if (arr[i] <= k)
            {
                k++;
            }
            else
            {
                // Kyunki array sorted hai, agar arr[i] > k ho gaya,
                // toh aage ke saare elements bhi > k hi honge.
                break;
            }
        }
        return k;
    }
};

int main()
{
    Solution sol;

    // Example 1
    vector<int> arr1 = {2, 3, 4, 7, 11};
    int k1 = 5;
    cout << "Example 1 Output: " << sol.findKthPositive(arr1, k1) << endl; // Expected: 9

    // Example 2
    vector<int> arr2 = {1, 2, 3, 4};
    int k2 = 2;
    cout << "Example 2 Output: " << sol.findKthPositive(arr2, k2) << endl; // Expected: 6

    return 0;
}

// optimal
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return k + high + 1;
    }
};