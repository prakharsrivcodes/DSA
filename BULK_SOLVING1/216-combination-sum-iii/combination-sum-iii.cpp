class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subset;
        vector<vector<int>> ans;
        help(1, k , 0, n,subset, ans);
        return ans;
    }
    void help(int i, int k, int sumTillNow, int n, vector<int> &subset, vector<vector<int>> &ans){
        if(sumTillNow > n){
            return;
        }
        if(k == 0 ){
            if(sumTillNow == n){
                ans.push_back(subset);
            }
            return;
        }
        if(i == 10) return;
        sumTillNow+=i;
        subset.push_back(i);
        help(i+1, k - 1, sumTillNow, n ,subset, ans);
        sumTillNow-=i;
        subset.pop_back();

        help(i+1, k, sumTillNow, n,subset, ans);

    }
};