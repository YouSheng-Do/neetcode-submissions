class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> keyToVal;// key->key, val->(timestamp, value)
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyToVal[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // binary search
        // if (!keyToVal.count(key)) return "";
        // keyToVal[key] is sorted

        // if (timestamp < keyToVal[key][0].first) return "";
        // -INF, [p1, p2, p3, p4, .... , pn], INF
        //   l ,                            ,  r
        //   T , .......................    ,  F
        // true means timestamp >= p1.first
        // we want to find the last true
        // return l;

        if (!keyToVal.count(key)) return "";

        const auto& vec = keyToVal[key];

        int l = -1, r = vec.size();

        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (vec[m].first <= timestamp) l = m;
            else r = m;
        }

        return (l == -1) ? "" : vec[l].second;
    }
};
