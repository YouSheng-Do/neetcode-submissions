class Twitter {
public:
    Twitter() : timestamp(0) {
    }
    
    void postTweet(int userId, int tweetId) {
        // O(1)
        following[userId].insert(userId);
        tweets[userId].push_back(make_pair(timestamp, tweetId));
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        // O(n log 10) => O(n)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        // maitain the priority_queue size <= 10
        // return from most recent to least recent

        for (auto followee : following[userId]) {
            for (auto tweet : tweets[followee]) {
                minHeap.push(tweet);
                if (minHeap.size() > 10) minHeap.pop();
            }
        }

        vector<int> news;
        while (!minHeap.empty()) {
            auto [time, tweetId] = minHeap.top(); minHeap.pop();
            news.push_back(tweetId);
        }

        reverse(news.begin(), news.end());

        return news;
    }
    
    void follow(int followerId, int followeeId) {
        // O(1)
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // O(1)
        if (following[followerId].count(followeeId))
            following[followerId].erase(followeeId);
    }
private:
    unordered_map<int, vector<pair<int, int>>> tweets; // for every user, record their tweets with timestamp
    unordered_map<int, unordered_set<int>> following; // for every user, maintain their followee
    int timestamp;
};
