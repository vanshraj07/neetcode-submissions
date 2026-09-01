class Solution {
private:
    double distance(int x,int y){
        return sqrt(x*x+y*y);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>,
        vector<pair<double,pair<int,int>>>,
        greater<pair<double,pair<int,int>>>>pq;
        for(int i=0;i<points.size();i++){
            double dis=distance(points[i][0],points[i][1]);
            pq.push({dis,{points[i][0],points[i][1]}});
        }
        vector<vector<int>>ans;
        while(!pq.empty() && k--){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};
