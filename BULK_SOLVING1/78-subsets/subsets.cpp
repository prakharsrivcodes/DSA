class Solution {
public:
    void func(int ind, vector<int>& nums, int n, vector<int>& sub, vector<vector<int>>& ans) {
        if(ind == n) {
            ans.push_back(sub);
            return;
        }
        // Pick element
        sub.push_back(nums[ind]);
        func(ind + 1, nums, n, sub, ans);
        // Do not pick the element
        sub.pop_back();
        func(ind + 1, nums, n, sub, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        func(0, nums, nums.size(), sub, ans);
        return ans;
    }
};