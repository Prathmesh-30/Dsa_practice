class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n= arr.size();
        long long sum =0 ,maxi=LONG_MIN;
        for(int i=0;i<n;i++){
            sum += arr[i];
            
            if(sum > maxi){
                maxi=sum ;
            }
            if(sum<0){
                sum=0;
            }
        }
        return (int) maxi ;
    }
};