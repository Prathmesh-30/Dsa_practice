class Solution {
public:
    string largestOddNumber(string num) {

        string result="";
        int n= num.size();
        bool odd= false;

        for( int i=n-1;i>=0;i--){
            int number= num[i]-'0';
            if(odd){
                result += num[i];

            }
            else if(number %2 ==1){
                result += num[i];
                odd= true ;
            }
            else {
                continue;
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};