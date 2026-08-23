class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int ans=INT_MIN;
        for(auto it:st){
            if(st.count(it-1)==0){
                int start=it;
                int len=0;
                while(st.count(start++)){
                    len++;
                }
                ans=max(ans,len);
            }
        }
        return ans;
    }
};
