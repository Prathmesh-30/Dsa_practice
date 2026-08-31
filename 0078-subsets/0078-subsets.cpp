class Solution {
public:

    void solve(int ind, vector<int>& nums,
               vector<int>& temp,
               vector<vector<int>>& ans) {

        if(ind == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // TAKE
        temp.push_back(nums[ind]);

        solve(ind + 1, nums, temp, ans);

        // REMOVE what we took
        temp.pop_back();

        // DON'T TAKE
        solve(ind + 1, nums, temp, ans);
    }


    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> temp;
        vector<vector<int>> ans;

        solve(0, nums, temp, ans);

        return ans;
    }
};