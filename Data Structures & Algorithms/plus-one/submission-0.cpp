class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int>ans;
        int j=0;
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            if(digits[i]==9){
                cnt++;
            }
            else{
                j=i;
                break;
            }
        }
        if(cnt==n){
            ans.push_back(1);
            for(int i=0;i<n;i++){
                ans.push_back(0);
            }
        }
        else{
            for(int i=0;i<j;i++){
                ans.push_back(digits[i]);
            }
            ans.push_back(digits[j]+1);
            for(int i=j+1;i<n;i++){
                ans.push_back(0);
            }
        }
        return ans;
    }
};
