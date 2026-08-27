class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>mpp;
        for(int i=0;i<t.size();i++){
            mpp[t[i]]++;
        }
        int l=0,r=0;
        int sIndex=-1;
        int cnt=0;
        int miniLen=INT_MAX;
        while(r<s.size()){
            if(mpp[s[r]]>0){
                cnt++;
            }
            mpp[s[r]]--;
            while(cnt==t.size()){
                if(r-l+1<miniLen){
                    miniLen=min(miniLen,r-l+1);
                    sIndex=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        if(sIndex==-1) return "";
        return s.substr(sIndex,miniLen);
    }
};
