class Solution {
private:
    bool alphaNum(char ch){
        return (ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9');
    }
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int l=0,r=n-1;
        while(l<=r){
            if(!alphaNum(s[l])){
                l++;
            }
            else if(!alphaNum(s[r])){
                r--;
            }
            else {
                if(tolower(s[l])!=tolower(s[r])){
                    return false;
                }
                l++;
                r--;
            }
        }
        return true;
    }
};
