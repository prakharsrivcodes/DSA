#include <iostream>
using namespace std;

int main()
{
    string num = "354270";

    for (int i = num.size() - 1; i >= 0; i--)
    {
        if ((num[i] - '0') % 2 == 1)
        {
            cout << num.substr(0, i + 1);
            return 0;
        }
    }

    cout << "";
}