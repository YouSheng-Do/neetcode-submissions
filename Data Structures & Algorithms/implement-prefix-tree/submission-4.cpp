class PrefixTree {
private:
    struct TrieNode {
        vector<TrieNode*> children;
        bool isEnd;
        TrieNode() : children(26, nullptr), isEnd(false) {};
    };
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (!cur->children[c - 'a']) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (!cur->children[c - 'a']) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        // insert : "aaaaaaa"
        // search : "aaaaaa"
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (auto c : prefix) {
            if (!cur->children[c - 'a']) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }

        return true;
    }
};
