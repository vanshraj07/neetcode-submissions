class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int l=0;
        int r=n-1;
        int maxA=INT_MIN;
        while(l<r){
            maxA=max(maxA,min(heights[l],heights[r])*(r-l));
            if(heights[l]<heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxA;
    }
};
