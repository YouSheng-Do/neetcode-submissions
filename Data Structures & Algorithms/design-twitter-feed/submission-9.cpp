class Twitter {
public:
    Twitter() : timestamp(0) {
    }
    
    void postTweet(int userId, int tweetId) {
        // O(1)
        tweets[userId].push_back(make_pair(timestamp, tweetId));
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        // F = number of followees
        // initialize heap: O(F log F)
        // get at most 10 tweets: O(10 log F)
        // Time: O((F + 10) log F)
        // Space: O(F)
        priority_queue<tuple<int, int, int>> maxHeap; // {time, followeeId, index}

        // tweets from userId
        if (!tweets[userId].empty()) 
            maxHeap.push({
                tweets[userId].back().first, 
                userId, 
                tweets[userId].size() - 1});

        // tweets from followee
        for (auto followee : following[userId]) {
            if (!tweets[followee].empty()) 
                maxHeap.push({
                    tweets[followee].back().first,
                    followee, 
                    tweets[followee].size() - 1
                    });
        }

        vector<int> news;
        while (news.size() < 10 && !maxHeap.empty()) {
            auto [time, followeeId, i] = maxHeap.top(); maxHeap.pop();
            news.push_back(tweets[followeeId][i].second);
            if (i > 0)
                maxHeap.push({
                    tweets[followeeId][i - 1].first,
                    followeeId, 
                    i - 1
                    });
        }

        return news;
    }
    
    void follow(int followerId, int followeeId) {
        // O(1)
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // O(1)
        following[followerId].erase(followeeId);
    }
private:
    unordered_map<int, vector<pair<int, int>>> tweets; // for every user, record their tweets with timestamp
    unordered_map<int, unordered_set<int>> following; // for every user, maintain their followee
    int timestamp;
};
