class LRUCache {
public:
    unordered_map<int, pair<int, int>> cache; // key->key, val->(val, timestamp)
    int timestamp; // timestamp++ when we call get()/put()
    int capacity;
    LRUCache(int capacity) : capacity(capacity), timestamp(0) {

    }
    
    int get(int key) {
        timestamp++;
        if (!cache.count(key)) return -1;

        cache[key].second = timestamp;

        return cache[key].first;
    }
    
    void put(int key, int value) {
        timestamp++;
        if (cache.count(key)) {
            cache[key].first = value;
            cache[key].second = timestamp;
            return;
        }
        if (cache.size() >= capacity) {
            int lru_key = -1;
            int minTime = INT_MAX;
            for (auto [key, p] : cache) {
                if (p.second < minTime) {
                    lru_key = key;
                    minTime = p.second;
                }
            }
            // cout << lru_key << endl;
            cache.erase(lru_key);
        }

        cache[key] = make_pair(value, timestamp);
    }
};
