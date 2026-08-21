struct ListNode {
    int val;
    int key;
    ListNode* prev;
    ListNode* next;
    ListNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
    ListNode(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};
class LRUCache {
public:
    unordered_map<int, ListNode*> cache; // key->key, val->ListNode(val)
    int capacity;
    ListNode* head;
    ListNode* tail;
    LRUCache(int capacity) : capacity(capacity) {
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;

        ListNode* cur = cache[key];
        remove(cur);
        insertHead(cur);

        return cur->val;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            ListNode* cur = cache[key];
            cur->val = value;
            remove(cur);
            insertHead(cur);
            return;
        }
        if (cache.size() >= capacity) {
            ListNode* cur = tail->prev;
            cache.erase(cur->key);
            remove(cur);
            delete cur;
        }

        ListNode* cur = new ListNode(key, value);
        insertHead(cur);
        cache[key] = cur;
    }
private:
    void remove(ListNode* cur) {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }
    void insertHead(ListNode* cur) {
        cur->next = head->next;
        cur->prev = head;
        head->next->prev = cur;
        head->next = cur;
    }
};
