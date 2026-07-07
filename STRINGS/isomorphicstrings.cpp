#include <iostream>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    unordered_map<char, char> mp1;
    unordered_map<char, char> mp2;

    for (int i = 0; i < s.length(); i++)
    {
        char ch1 = s[i];
        char ch2 = t[i];

        if (mp1.find(ch1) == mp1.end() && mp2.find(ch2) == mp2.end())
        {
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }
        else
        {
            if (mp1[ch1] != ch2 || mp2[ch2] != ch1)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    string s = "egg";
    string t = "add";

    cout << isIsomorphic(s, t);

    return 0;
}