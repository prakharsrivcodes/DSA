// better#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string &s, int l, int r)
{

    while (l < r)
    {

        if (s[l] != s[r])
        {
            return false;
        }

        l++;
        r--;
    }

    return true;
}

string longestPalindrome(string s)
{

    string ans = "";

    for (int l = 0; l < s.length(); l++)
    {

        for (int r = l; r < s.length(); r++)
        {

            if (isPalindrome(s, l, r))
            {

                if (r - l + 1 > ans.length())
                {
                    ans = s.substr(l, r - l + 1);
                }
            }
        }
    }

    return ans;
}

int main()
{

    string s = "babad";

    longestPalindrome(s);

    return 0;
}

// expand around centre optimal code
#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s)
{

    int start = 0;
    int maxLen = 1;

    auto expand = [&](int l, int r)
    {
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {

            if (r - l + 1 > maxLen)
            {

                maxLen = r - l + 1;
                start = l;
            }

            l--;
            r++;
        }
    };

    for (int i = 0; i < s.length(); i++)
    {

        expand(i, i); // Odd Length

        expand(i, i + 1); // Even Length
    }

    return s.substr(start, maxLen);
}

int main()
{

    string s = "babad";

    cout << longestPalindrome(s);

    return 0;
}