#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string frequencySort(string s)
{

    vector<int> freq(128, 0);

    for (char ch : s)
        freq[ch]++;

    auto cmp = [&](char a, char b)
    {
        if (freq[a] == freq[b])
            return a < b;

        return freq[a] > freq[b];
    };

    sort(s.begin(), s.end(), cmp);

    return s;
}

int main()
{

    string s = "tree";

    cout << frequencySort(s);

    return 0;
}

// 2nd approach
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

string frequencySort(string s)
{

    unordered_map<char, int> freq;

    for (char ch : s)
        freq[ch]++;

    vector<pair<char, int>> freqArr;

    for (auto [ch, fq] : freq)
        freqArr.push_back({ch, fq});

    auto cmp = [](pair<char, int> &a, pair<char, int> &b)
    {
        return a.second > b.second;
    };

    sort(freqArr.begin(), freqArr.end(), cmp);

    string ans = "";

    for (auto [ch, fq] : freqArr)
        ans.append(fq, ch);

    return ans;
}

int main()
{

    string s = "tree";

    cout << frequencySort(s);
}

// optimal approach bucket sort
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string frequencySort(string s)
{

    unordered_map<char, int> freq;

    for (char ch : s)
        freq[ch]++;

    vector<vector<char>> bucketData(s.length() + 1);

    for (auto [ch, fq] : freq)
        bucketData[fq].push_back(ch);

    string ans = "";

    for (int fq = s.length(); fq >= 1; fq--)
    {

        for (char ch : bucketData[fq])
            ans.append(fq, ch);
    }

    return ans;
}

int main()
{

    string s = "tree";

    cout << frequencySort(s);
}