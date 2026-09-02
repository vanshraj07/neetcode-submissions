class Twitter {
    unordered_map<int,vector<pair<int,int>>>tweetMap;
    unordered_map<int,unordered_set<int>>followMap;
    int time=0;   //for Recently Used
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        for(auto it:tweetMap[userId]){
            pq.push({it.first,it.second});
        }
        for(auto followeeiterator:followMap[userId]){
            for(auto tweetsofFollowee:tweetMap[followeeiterator]){
                pq.push(tweetsofFollowee);
            }
        }
        vector<int>tweets;
        int temp=10;
        while(!pq.empty() && temp>0){
            tweets.push_back(pq.top().second);
            pq.pop();
            temp--;
        }
        return tweets;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            followMap[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
