class RandomizedSet {
private:
    vector<int> data;
    unordered_map<int, int> data_to_index; // key:data -> value:index
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (data_to_index.count(val)) return false;
        data.push_back(val);
        data_to_index[val] = data.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!data_to_index.count(val)) return false;
        int index = data_to_index[val];
        int last = data.back();
        data[index] = last;
        data_to_index[last] = index;
        data_to_index.erase(val);
        data.pop_back();
        return true;
    }
    
    int getRandom() {
        return data[rand() % data.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */