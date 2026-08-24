class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>nums;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                nums.push_back(matrix[i][j]);
            }
        }
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>target){
                r=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
