// optimal
#include <iostream>
#include <string>
using namespace std;

string removeOuterParentheses(string s)
{
    string ans = "";
    int cnt = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            if (cnt > 0)
            {
                ans += s[i];
            }

            cnt++;
        }
        else
        {
            cnt--;

            if (cnt > 0)
            {
                ans += s[i];
            }
        }
    }

    return ans;
}

int main()
{
    string s = "(()())(())";
    cout << removeOuterParentheses(s);

    return 0;
}

// brute lil
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeOuterParentheses(string s)
{
    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            if (!st.empty())
            {
                ans += s[i];
            }

            st.push('(');
        }
        else
        {
            st.pop();

            if (!st.empty())
            {
                ans += s[i];
            }
        }
    }

    return ans;
}

int main()
{
    string s = "(()())(())";
    cout << removeOuterParentheses(s);

    return 0;
}