class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int l=0,r=n-1;
        int lmaxi=0;
        int rmaxi=0;
        while(l<r){
            if(height[l]<height[r]){
                if(lmaxi<height[l]){
                    lmaxi=max(lmaxi,height[l]);
                }
                else{
                    ans+=(lmaxi-height[l]);
                }
                l++;
            }
            else{
                if(rmaxi<height[r]){
                    rmaxi=max(rmaxi,height[r]);
                }
                else{
                    ans+=(rmaxi-height[r]);
                }
                r--;
            }
        }
        return ans;
    }
};
