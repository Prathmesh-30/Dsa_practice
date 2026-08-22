class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.size();
        int l=0;
        int maxlen=0;
        int maxfreq=0;
        unordered_map<char,int>mp;
        for( int r=0;r<n;r++){
            mp[s[r]]++;
            maxfreq=max(maxfreq,mp[s[r]]);
        
        while((r-l+1)-maxfreq>k){
            mp[s[l]]--;
            l++;

        }
        maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};