class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end());
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            st.push(v[i]);
        }
        double prevtime=0;
        int ans=0;
        while(!st.empty()){
            int pos=st.top().first;
            int spd=st.top().second;
            st.pop();
            double currtime=(double)(target-pos)/spd;
            if(currtime>prevtime){
                ans++;
                prevtime=currtime;
            }
        }
        return ans;
    }
};
