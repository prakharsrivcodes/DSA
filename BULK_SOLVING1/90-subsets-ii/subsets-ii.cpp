class Solution {
public:
    void func(int ind, vector<int>& nums, int n, vector<int>&sub, set<vector<int>>& st) {
        if(ind == n) {
            st.insert(sub);
            return;
        }
        // Pick
        sub.push_back(nums[ind]);
        func(ind + 1, nums, n, sub, st);
        // Not pick
        sub.pop_back();
        func(ind + 1, nums, n, sub, st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> sub;
        set<vector<int>> st;
        func(0, nums, nums.size(), sub, st);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};