class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int>v;
        for(int i=0;i<m;i++){
            v.push_back(nums1[i]);
        }
        for(int i=0;i<n;i++){
            v.push_back(nums2[i]);
        }
        sort(v.begin(),v.end());
        int size=v.size();
        if(size%2!=0){
            return v[size/2];
        }
        return (double)(v[size/2]+v[(size-1)/2])/2;
    }
};
