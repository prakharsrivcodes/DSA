// brute
#include <iostream>
#include <vector>
using namespace std;

int totalHours(vector<int>& piles, int speed)
{
    int total = 0;

    for(int i = 0; i < piles.size(); i++)
    {
        total += piles[i] / speed;

        if(piles[i] % speed != 0)
            total++;
    }

    return total;
}

int minEatingSpeed(vector<int>& piles, int h)
{
    int maxi = piles[0];

    // Find Maximum Element
    for(int i = 1; i < piles.size(); i++)
    {
        if(piles[i] > maxi)
            maxi = piles[i];
    }

    // Try every possible speed
    for(int speed = 1; speed <= maxi; speed++)
    {
        int reqTime = totalHours(piles, speed);

        if(reqTime <= h)
            return speed;
    }

    return -1;
}

int main()
{
    vector<int> piles = {3,6,7,11};
    int h = 8;

    cout << minEatingSpeed(piles, h);

    return 0;
}


// OPTIMALLLLLLLLLLLLLLLLl
#include <iostream>
#include <vector>
using namespace std;

int totalHours(vector<int>& piles, int speed)
{
    int total = 0;

    for(int i = 0; i < piles.size(); i++)
    {
        total += piles[i] / speed;

        if(piles[i] % speed != 0)
            total++;
    }

    return total;
}

int minEatingSpeed(vector<int>& piles, int h)
{
    int low = 1;
    int high = piles[0];

    // Find Maximum Element
    for(int i = 1; i < piles.size(); i++)
    {
        if(piles[i] > high)
            high = piles[i];
    }

    int ans = high;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        int reqTime = totalHours(piles, mid);

        if(reqTime <= h)
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
    vector<int> piles = {3,6,7,11};
    int h = 8;

    cout << minEatingSpeed(piles, h);

    return 0;
}