class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        int maxi=INT_MIN;
        for(int i=0;i<k;i++){
            maxi=max(maxi,nums[i]);
        }
        ans.push_back(maxi);
        int l=1;
        int r=k;
        while(r<n){
            if(nums[l-1]!=maxi){
                maxi=max(maxi,nums[r]);
            }
            else{
                maxi=nums[l];
                for(int i=l;i<=r;i++){
                    maxi=max(maxi,nums[i]);
                }
            }
            ans.push_back(maxi);
            l++;
            r++;
        }
        return ans;
    }
};
