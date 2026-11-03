class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int range = 0;
        for (int i = 0; i < n; i++) {
            range += stones[i];
        }
        int w = range / 2;
        vector<vector<bool>> t(n + 1, vector<bool>(w + 1, false));
        for (int i = 0; i <= n; i++) {
            t[i][0] = true;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= w; j++) {
                if (stones[i - 1] <= j) {;
                    t[i][j] = t[i - 1][j] || t[i - 1][j - stones[i - 1]];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        vector<int> v;
        for (int j = 0; j <= w; j++) {
            if (t[n][j] == true) {
                v.push_back(j);
            }
        }
        int mn = INT_MAX;
        for (int i = 0; i < v.size(); i++) {
            mn = min(mn, range - 2 * v[i]);
        }
        return mn;
    }
};