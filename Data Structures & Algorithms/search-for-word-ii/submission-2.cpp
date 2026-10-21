class Solution {
    struct TrieNode {
        vector<TrieNode*> children;
        bool isEnd;
        TrieNode() : children(26, nullptr), isEnd(false) {}
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        // add words into Trie
        for (auto word : words) {
            // dfs
            TrieNode* cur = root;
            for (auto c : word) {
                if (!cur->children[c - 'a']) cur->children[c - 'a'] = new TrieNode();
                cur = cur->children[c - 'a'];
            }
            cur->isEnd = true;
        }

        unordered_set<string> ans;
        // dfs from all pos
        string prefix = "";
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(i, j, ans, prefix, board, root);
            }
        }

        return vector<string>(ans.begin(), ans.end());
    }
    void dfs(int i, int j, unordered_set<string>& ans, string& prefix, vector<vector<char>>& board, TrieNode* cur) {
        // match the whole word
        if (cur->isEnd) {
            ans.insert(prefix);
        }

        // boundary check
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '.') return;

        // no that prefix match any words
        char c = board[i][j];
        if (!cur->children[c - 'a']) return;

        // if board[i][j] can be add as prefix of some words
        board[i][j] = '.';
        prefix += c;
        dfs(i + 1, j, ans, prefix, board, cur->children[c - 'a']);
        dfs(i - 1, j, ans, prefix, board, cur->children[c - 'a']);
        dfs(i, j + 1, ans, prefix, board, cur->children[c - 'a']);
        dfs(i, j - 1, ans, prefix, board, cur->children[c - 'a']);
        prefix.pop_back();
        board[i][j] = c;
    }
};
