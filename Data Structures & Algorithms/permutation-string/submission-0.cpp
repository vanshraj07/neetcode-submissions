class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        sort(s1.begin(),s1.end());
        int l=0,r=0;
        while(r<n){
            if(r-l+1==m){
                string temp=s2.substr(l,m);
                sort(temp.begin(),temp.end());
                if(s1==temp){
                    return true;
                }
                l++;
            }
            r++;
        }
        return false;
    }
};
