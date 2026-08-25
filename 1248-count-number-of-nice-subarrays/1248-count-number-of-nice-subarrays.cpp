class Solution {
public:

    int atMost(vector<int>& nums, int k) {

        if (k < 0)
            return 0;

        int l = 0;
        int sum = 0;
        int cnt = 0;

        for (int r = 0; r < nums.size(); r++) {

            if (nums[r] % 2 != 0)
                sum++;

            while (sum > k) {
                if (nums[l] % 2 != 0)
                    sum--;

                l++;
            }

            cnt += r - l + 1;
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {

        return atMost(nums, k) - atMost(nums, k - 1);
    }
};