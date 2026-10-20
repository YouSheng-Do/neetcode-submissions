class PrefixTree {
private:
    struct TrieNode {
        vector<TrieNode*> children;
        bool isEnd;
        TrieNode() : isEnd(false), children(26, nullptr) {};
    };
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int i = 0;
        int sz = word.size();
        TrieNode* cur = root;
        while (i < sz) {
            char c = word[i];
            if (!cur->children[c - 'a']) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
            ++i;
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        int i = 0;
        int sz = word.size();
        TrieNode* cur = root;
        while (i < sz) {
            char c = word[i];
            if (!cur->children[c - 'a']) {
                return false;
            }
            cur = cur->children[c - 'a'];
            ++i;
        }
        // insert : "aaaaaaa"
        // search : "aaaaaa"
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        int i = 0;
        int sz = prefix.size();
        TrieNode* cur = root;
        while (i < sz) {
            char c = prefix[i];
            if (!cur->children[c - 'a']) {
                return false;
            }
            cur = cur->children[c - 'a'];
            ++i;
        }

        return true;
    }
};
