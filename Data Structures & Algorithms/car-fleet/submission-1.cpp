class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end());
        double prevtime=0;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            double currtime=(double)(target-v[i].first)/v[i].second;
            if(currtime>prevtime){
                ans++;
                prevtime=currtime;
            }
        }
        return ans;
    }
};
