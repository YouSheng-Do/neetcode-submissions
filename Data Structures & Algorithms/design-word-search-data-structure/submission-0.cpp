class WordDictionary {
    struct TrieNode {
        bool isEnd;
        unordered_map<char, TrieNode*> children;
        TrieNode() : isEnd(false) {}
    };
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (!cur->children.count(c)) cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        return match(0, word, root);
    }
    bool match(int i, const string& word, TrieNode* cur) {
        if (i == word.size() && cur->isEnd) return true;
        if (word[i] == '.') {
            for (auto [c, child] : cur->children) {
                if (match(i + 1, word, child)) return true;
            }
        }
        else {
            char c = word[i];
            if (!cur->children.count(c)) return false;
            return match(i + 1, word, cur->children[c]);
        }

        return false;
    }
};
