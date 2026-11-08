class Solution {
public:
    int numberOfWays(int n, int x) {
        int MOD = 1e9 + 7;
        vector<int> val;
        for(int i = 1; pow(i,x) <= n; i++){
            val.push_back(pow(i,x));
        }
        int s = val.size();
        vector<vector<int>> t(s+1, vector<int>(n+1, 0));
        for (int i= 0;i <= s; i++){
            t[i][0] = 1;
        }
        for(int i = 1; i <= s; i++){
            for(int j = 1; j <= n; j++){
                if(val[i-1] <= j){
                    int no = t[i-1][j];
                    int yes = t[i-1][j- val[i-1]];
                    t[i][j] = (no + yes)%MOD;
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[s][n];
    }
};