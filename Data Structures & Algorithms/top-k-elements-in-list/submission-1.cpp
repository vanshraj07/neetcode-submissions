class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        vector<pair<int,int>>v;
        for(auto it:mpp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        vector<int>ans;
        int ind=0;
        while(k--){
            ans.push_back(v[ind].second);
            ind++;
        }
        return ans;
    }
};
