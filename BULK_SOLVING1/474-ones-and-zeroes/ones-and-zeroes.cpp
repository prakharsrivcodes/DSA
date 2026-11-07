class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int t = strs.size();
        vector<vector<vector<int>>>z(t+1, vector<vector<int>>(m + 1, vector<int> (n + 1, 0)));
        for(int i = 1; i <= t; i++){
            int zeroes  = 0;
            int ones = 0;
            for( auto ch : strs[i-1]){
                if(ch == '0') zeroes++;
                else ones++;
            }
            for(int j = 0; j <= m ; j++){
                for(int k = 0; k <= n; k++){
                    int no = z[i-1][j][k];
                    int yes = 0;
                    if(zeroes <= j && ones <= k){
                        yes = 1 + z[i-1][j - zeroes][k - ones];
                    }
                    z[i][j][k] = max(no , yes);
                }
            }
        }
        return z[t][m][n];
    }
};