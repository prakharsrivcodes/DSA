#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        bool ok = true;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if ((i % 2) != (x % 2))
                ok = false;
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}