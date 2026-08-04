class Solution {
public:
    int numOfBouqets(vector<int>& bloomDay, int k, int day) {
        int count=0, ans=0, i=0;
        while(i<bloomDay.size()) {
            if(bloomDay[i]<=day) count++;
            else count=0;
            if(count==k) {
                ans++;
                count=0;
            } i++;
        }
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi=0;
        for(int num:bloomDay) maxi=max(maxi,num);
        int start=0, end=maxi, ans=-1;
        while(start<=end) {
            int mid=(start+end)/2;
            int res=numOfBouqets(bloomDay,k,mid);
            if(res>=m) {
                ans=mid;
                end=mid-1;
            } else start=mid+1;
        }
        return ans;
    }
};