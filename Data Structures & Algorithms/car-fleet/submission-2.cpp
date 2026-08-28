class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({position[i],speed[i]});
        }
        double prevtime=0;
        int ans=0;
        while(!pq.empty()){
            int pos=pq.top().first;
            int spd=pq.top().second;
            pq.pop();
            double currtime=(double)(target-pos)/spd;
            if(currtime>prevtime){
                ans++;
                prevtime=currtime;
            }
        }
        return ans;
    }
};
