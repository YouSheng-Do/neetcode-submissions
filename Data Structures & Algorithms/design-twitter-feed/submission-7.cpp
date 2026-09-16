class Twitter {
    struct ListNode {
        int time;
        int tweetId;
        ListNode* next;
        ListNode(int time, int tweetId, ListNode* next) : time(time), tweetId(tweetId), next(next) {}
    };
    struct cmp {
        bool operator()(const ListNode* a, const ListNode* b) const {
            return a->time < b->time;
        }
    };
public:
    Twitter() : timestamp(0) {
    }
    
    void postTweet(int userId, int tweetId) {
        // O(1)
        ListNode* newTweet = new ListNode(timestamp, tweetId, tweetsList[userId]);
        tweetsList[userId] = newTweet;

        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        // F = number of followees
        // initialize heap: O(F log F)
        // get at most 10 tweets: O(10 log F)
        // Time: O((F + 10) log F)
        // Space: O(F)
        priority_queue<ListNode*, vector<ListNode*>, cmp> maxHeap;
        // maitain the priority_queue size <= 10
        // return from most recent to least recent

        // tweets from userId
        if (tweetsList[userId])
            maxHeap.push(tweetsList[userId]);

        // tweets from followee
        for (auto followee : following[userId]) {
            if (tweetsList[followee])
                maxHeap.push(tweetsList[followee]);
        }

        vector<int> news;
        while (news.size() < 10 && !maxHeap.empty()) {
            auto node = maxHeap.top(); maxHeap.pop();
            news.push_back(node->tweetId);
            if (node->next) maxHeap.push(node->next);
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
    unordered_map<int, ListNode*> tweetsList; // for every user, record their tweets with timestamp
    unordered_map<int, unordered_set<int>> following; // for every user, maintain their followee
    int timestamp;
};
