class TimeMap {
    map<string,vector<pair<int,string>>>mpp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int low=0;
        int high=mpp[key].size()-1;
        string ans="";
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mpp[key][mid].first<=timestamp){
                ans=mpp[key][mid].second;
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return ans;
    }
};
