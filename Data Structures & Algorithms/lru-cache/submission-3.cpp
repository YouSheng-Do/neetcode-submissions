class LRUCache {
public:
    map<int, int> timeToKey;// key->timestamp, val->key
    unordered_map<int, pair<int, int>> cache;
    int capacity;
    int timestamp;
    LRUCache(int capacity) : capacity(capacity), timestamp(0) {
        
    }
    
    int get(int key) {
        timestamp++;

        if (!cache.count(key)) return -1;

        auto& [val, time] = cache[key];
        timeToKey.erase(time);
        timeToKey[timestamp] = key;
        time = timestamp;

        return val;
    }
    
    void put(int key, int value) {
        timestamp++;
        if (cache.count(key)) {
            auto& [val, time] = cache[key];
            val = value;
            timeToKey.erase(time);
            time = timestamp;
            timeToKey[time] = key;
            return;
        }
        if (cache.size() >= capacity) {
            auto it = timeToKey.begin();
            int minTime = it->first;
            int minKey = it->second;
            timeToKey.erase(minTime);
            cache.erase(minKey);
        }
        cache[key] = make_pair(value, timestamp);
        timeToKey[timestamp] = key;
    }
};
