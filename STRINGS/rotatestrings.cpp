// self thought
#include <iostream>
#include <algorithm>
using namespace std;

bool rotateString(string s, string goal)
{
    if (s.length() != goal.length())
    {
        return false;
    }

    int n = s.length();

    for (int k = 1; k <= n; k++)
    {
        reverse(s.begin(), s.end());

        reverse(s.begin(), s.begin() + k);

        reverse(s.begin() + k, s.end());

        if (s == goal)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    string s = "abcde";
    string goal = "cdeab";

    cout << rotateString(s, goal);

    return 0;
}

// optimal
#include <iostream>
using namespace std;

bool rotateString(string s, string goal)
{
    if (s.length() != goal.length())
    {
        return false;
    }

    string temp = s + s;

    if (temp.find(goal) != string::npos)
    {
        return true;
    }

    return false;
}

int main()
{
    string s = "abcde";
    string goal = "cdeab";

    cout << rotateString(s, goal);

    return 0;
}