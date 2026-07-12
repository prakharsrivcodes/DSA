#include <iostream>
#include <string>
using namespace std;

int maxDepth(string s)
{

    int cnt = 0;
    int maxDepth = 0;

    for (char ch : s)
    {

        if (ch == '(')
        {
            cnt++;
            maxDepth = max(maxDepth, cnt);
        }

        else if (ch == ')')
        {
            cnt--;
        }
    }

    return maxDepth;
}

int main()
{

    string s = "(1+(2*3)+((8)/4))+1";

    cout << maxDepth(s);

    return 0;
}