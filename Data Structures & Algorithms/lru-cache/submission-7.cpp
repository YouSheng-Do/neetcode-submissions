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
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        cur->next = head->next;
        cur->prev = head;
        head->next->prev = cur;
        head->next = cur;

        return cur->val;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            ListNode* cur = cache[key];
            cur->val = value;
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            cur->next = head->next;
            cur->prev = head;
            head->next->prev = cur;
            head->next = cur;
            return;
        }
        if (cache.size() >= capacity) {
            ListNode* cur = tail->prev;
            cache.erase(cur->key);
            cur->prev->next = tail;
            tail->prev = cur->prev;
            // delete cur;
        }

        ListNode* cur = new ListNode(key, value);
        cur->prev = head;
        cur->next = head->next;
        head->next->prev = cur;
        head->next = cur;
        cache[key] = cur;
    }
};
