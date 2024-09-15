// leetcode 355. Design Twitter

class Twitter {
    struct Tweet{
        int tweetId;
        int time;
        Tweet(int id, int t): tweetId(id), time(t){};
    };

    // global clock
    int time;

    // map: userid to tweets that the user has posted
    unordered_map<int, vector<Tweet>> tweets;

    // map: userid to unordered_set userid, userid to his following
    unordered_map<int, unordered_set<int>> following;

    class comp{
        public:
            bool operator()(const Tweet&a, const Tweet&b){
                return a.time > b.time;
            }
    };

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        // if(tweets.find(userId) == tweets.end()){
        //     tweets.insert(userId, {Tweet(tweetId, time++)});
        // }
        // else{
        //     tweets[userId].push_back(Tweet(tweetId,time++));
        // }
        tweets[userId].push_back(Tweet(tweetId, time++));
    }
    
    // returning the tweetId of 10 most recent tweets done by me or by following
    vector<int> getNewsFeed(int userId) {
        // min-heap to keep track of top 10 most recent tweets
        priority_queue<Tweet, vector<Tweet>, comp> minHeap;
        
        // add my tweets
        if(tweets.find(userId) != tweets.end()){
            for(auto tweet: tweets[userId]){
                minHeap.push(tweet);
                if(minHeap.size() > 10) minHeap.pop(); // remove the oldest tweet
            }
        }
        // add tweets from my following
        if(following.find(userId) != following.end()){
            auto myFollowings = following[userId];
            for(auto followeeId: myFollowings){
                if(tweets.find(followeeId) != tweets.end()){
                    for(auto tweet: tweets[followeeId]){
                        minHeap.push(tweet);
                        if(minHeap.size() > 10) minHeap.pop(); // remove the oldest tweet
                    }
                }
            }
        }
        // now i will have oldest tweets fom userid and from the followings of userid
        vector<int>newsFeedTweets;
        while(!minHeap.empty()){
            auto [tweetId, time] = minHeap.top();
            minHeap.pop();
            newsFeedTweets.push_back(tweetId);
        }
        reverse(newsFeedTweets.begin(),newsFeedTweets.end());
        return newsFeedTweets;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return; // cannot follow myself
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following.find(followerId) != following.end()) following[followerId].erase(followeeId);
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