class Solution {
    struct TrieNode {
        vector<TrieNode*> children;
        int index;
        int refs;
        TrieNode() : children(26, nullptr), index(-1), refs(0) {}
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        // add words into Trie
        for (int i = 0; i < words.size(); ++i) {
            // dfs
            string word = words[i];
            TrieNode* cur = root;
            cur->refs++;
            for (auto c : word) {
                if (!cur->children[c - 'a']) cur->children[c - 'a'] = new TrieNode();
                cur = cur->children[c - 'a'];
                cur->refs++;
            }
            cur->index = i;
        }

        vector<string> ans;
        // dfs from all pos
        string prefix = "";
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(i, j, ans, prefix, board, root);
            }
        }

        return ans;
    }
    int dfs(int i, int j, vector<string>& ans, string& prefix, vector<vector<char>>& board, TrieNode* cur) {
        if (!cur->refs) return 0;

        // match the whole word
        int found = 0;
        if (cur->index != -1) {
            ans.push_back(prefix);
            cur->index = -1;
            found++;
        }

        // boundary check
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '.') {
            cur->refs -= found;
            return found;
        }

        // no that prefix match any words
        char c = board[i][j];
        if (!cur->children[c - 'a']) {
            cur->refs -= found;
            return found;
        }

        // if board[i][j] can be add as prefix of some words
        board[i][j] = '.';
        prefix += c;
        found += dfs(i + 1, j, ans, prefix, board, cur->children[c - 'a']);
        found += dfs(i - 1, j, ans, prefix, board, cur->children[c - 'a']);
        found += dfs(i, j + 1, ans, prefix, board, cur->children[c - 'a']);
        found += dfs(i, j - 1, ans, prefix, board, cur->children[c - 'a']);
        prefix.pop_back();
        board[i][j] = c;
        cur->refs -= found;

        return found;
    }
};
