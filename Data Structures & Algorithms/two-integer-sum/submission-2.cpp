class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int l=0,r=nums.size()-1;
        while(l<r){
            if(v[l].first+v[r].first>target){
                r--;
            }
            else if(v[l].first+v[r].first<target){
                l++;
            }
            else{
                    return {min(v[l].second, v[r].second),
                    max(v[l].second, v[r].second)};
            }
        }
        return {};
    }
};