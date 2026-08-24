class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        int n= nums.size();
        if(goal < 0) return 0;
       int l=0,r=0,sum=0,cnt=0;
        while(r<nums.size()){
            sum += nums[r];
            while(sum>goal){
                sum = sum - nums[l];
                l=l+1;
            }
            cnt= cnt+(r-l+1);
            r=r+1;

        }
        return cnt ;
    }
     int numSubarraysWithSum(vector<int>& nums, int goal) {

        return atMost(nums, goal) - atMost(nums, goal - 1);
     }
};