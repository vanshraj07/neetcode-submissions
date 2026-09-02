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
        vector<pair<int,int>>feed=tweetMap[userId];
        for(auto followeeiterator:followMap[userId]){
            for(auto tweetsofFollowee:tweetMap[followeeiterator]){
                feed.push_back(tweetsofFollowee);
            }
        }
        sort(feed.begin(),feed.end(),greater<pair<int,int>>());
        vector<int>tweets;
        for(int i=0;i<min(10,(int)feed.size());i++){
            tweets.push_back(feed[i].second);
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
