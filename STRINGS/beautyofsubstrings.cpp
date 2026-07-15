#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int beautySum(string s) {

    int sum = 0;

    for(int i = 0; i < s.length(); i++) {

        int freq[26] = {0};

        for(int j = i; j < s.length(); j++) {

            freq[s[j] - 'a']++;

            int maxFreq = 0;
            int minFreq = 501;

            for(int k = 0; k < 26; k++) {

                if(freq[k] > 0) {

                    maxFreq = max(maxFreq, freq[k]);
                    minFreq = min(minFreq, freq[k]);
                }
            }

            sum += (maxFreq - minFreq);
        }
    }

    return sum;
}

int main() {

    string s = "aabcb";

    cout << beautySum(s);

    return 0;
}