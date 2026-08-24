class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        map<char,int>mpp;
        int ans=0;
        int l=0,r=0;
        while(r<n){
            if(mpp.find(s[r])==mpp.end()){
                mpp[s[r]]++;
            }
            else{
                while(mpp[s[r]]>0){
                    mpp[s[l]]--;
                    l++;
                }
                mpp[s[r]]++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
