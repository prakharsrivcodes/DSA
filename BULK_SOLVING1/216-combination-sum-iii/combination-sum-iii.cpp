class Solution {
public:
    void help(int start, int k, int sumTillNow, int n, vector<int>& subset,vector<vector<int>>& ans) {
        if (subset.size() == k) {
            if (sumTillNow == n) {
                ans.push_back(subset);
            }
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (sumTillNow + i > n) {
                break;
            }
            subset.push_back(i);

            help(i + 1, k, sumTillNow + i, n, subset, ans);

            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subset;
        help(1, k, 0, n, subset, ans);
        return ans;
    }
};