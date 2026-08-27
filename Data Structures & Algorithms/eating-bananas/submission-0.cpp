class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        while(l<=r){
            int m=(l+r)/2;
            long long totalTime=0;
            for(int i=0;i<piles.size();i++){
                totalTime+=(piles[i]+m-1)/m;
            }
            if(totalTime<=h){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};
