class Solution {
public:
    int findMin(vector<int>& arr) {
        int start=0,end=arr.size()-1,ans=arr[0];
        while(start<=end){
            int mid=start+(end-start)/2;


       if (arr[start] <= arr[end]){
        ans= min(ans,arr[start]);
        break;
       }
       if(arr[start] <= arr[mid]){
        ans= min(ans , arr[start]);
        start= mid+1;
       }
       else{
        end= mid-1;
        ans=min(ans,arr[mid]);

       }
 



 
    

           
            
  

    }
    return ans;
}
};