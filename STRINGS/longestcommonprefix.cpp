#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    sort(strs.begin(), strs.end());

    string first = strs[0];
    string last = strs[strs.size() - 1];

    string ans = "";

    for (int i = 0; i < first.length(); i++)
    {
        if (i >= last.length() || first[i] != last[i])
        {
            break;
        }

        ans += first[i];
    }

    return ans;
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};

    cout << longestCommonPrefix(strs);

    return 0;
}