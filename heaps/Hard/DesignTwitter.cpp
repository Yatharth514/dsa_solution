
class Twitter {
public:
    int time;
    unordered_map<int,vector<pair<int,int>>>tweets;
    unordered_map<int,unordered_set<int>>follows;

    Twitter() {
      time=0;  
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
        
    }
    
    vector<int> getNewsFeed(int userId) {
        follows[userId].insert(userId);
        vector<int>feed;
        priority_queue<pair<int,int>>latestFeed;
        for(auto &it :follows[userId])
        {
            for(auto &se:tweets[it])
            {
                latestFeed.push({se.first,se.second});
            }
           
        }
        int i =0;
        while(!latestFeed.empty()&&i<10)
        {
            feed.push_back(latestFeed.top().second);
            latestFeed.pop();
            i++;
        }
        return feed;
        
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);

        
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId)
        return;
        follows[followerId].erase(followeeId);
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */