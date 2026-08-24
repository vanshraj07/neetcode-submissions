class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        map<char,int>mpp;
        int l=0,r=0;
        int maxfreq=0;
        int ans=0;
        while(r<n){
            mpp[s[r]]++;
            maxfreq=max(maxfreq,mpp[s[r]]);
            while((r-l+1)>maxfreq+k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
