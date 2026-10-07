class Solution {
public:
    void combinationSum(int ind, vector<int>& arr, int target,
                        vector<vector<int>>& ans, vector<int>& candidates) {
        
        if (ind == arr.size()) {
            if (target == 0) {
                ans.push_back(candidates);
            }
            return;
        }

        if (arr[ind] <= target) {
            candidates.push_back(arr[ind]);

            combinationSum(ind, arr, target - arr[ind], ans, candidates);

            candidates.pop_back();
        }

        combinationSum(ind + 1, arr, target, ans, candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;

        combinationSum(0, candidates, target, ans, current);

        return ans;
    }
};