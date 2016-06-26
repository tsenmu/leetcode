class Twitter {
protected:
    class Tweet {
    public:
        Tweet(int time, int id)  {
            this->time = time;
            this->id = id;
        }
        int time;
        int id;
        bool operator<(const Tweet& l, const Tweet& r) {
            return l.time < r.time; 
        }
    }

    unordered_map<int, unordered_set<int>> m_followees;
    unordered_map<int, vector<Tweet>> m_tweets;

    int m_time;

public:
    /** Initialize your data structure here. */
    Twitter() {
        m_time = 0; 
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        m_tweets[userId].push_back(Tweet(m_time++, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        const unordered_set<int>& followees = m_followees[userId];
        for (auto it = followees.begin(); it != followees.end(); ++it)  {
             
        }
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        m_followees[followeeId].insert(followerId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        m_followees[followeeId].erase(followerId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */