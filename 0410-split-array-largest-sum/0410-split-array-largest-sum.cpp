class Solution {
public:
int cntS(vector<int>&arr,int P){
    int students=1;
    long long Pstudent=0;
    for(int i=0;i<arr.size();i++){
        if(Pstudent + arr[i] <= P){
               Pstudent += arr[i];
        }
        else{
            students += 1;
            Pstudent = arr[i];
        }
    }
    return students;
}
int FP(vector<int>& arr,int n,int m){
    if(m>n) return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<= high){
        int mid =(low+high)/2;
        int students=cntS(arr,mid);
        if(students>m){
            low= mid+1;
        }
        else{
            high=mid-1;
        }

    }
    return low;
}
    int splitArray(vector<int>& nums, int k) {
        return FP(nums,nums.size(),k);
        
    }
};