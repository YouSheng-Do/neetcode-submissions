class Solution {
public:
    unordered_map<int, int> root;
    int longestConsecutive(vector<int>& nums) {
        for (const int& x : nums) {
            root[x] = x;
        }
        
        for (const int& x : nums) {
            if (root.count(x - 1)) unite(x - 1, x);
            if (root.count(x + 1)) unite(x, x + 1);
        }

        int maxLen = 0;
        for (const int& x : nums) {
            root[x] = find(x);
            // cout << x << " " << root[x] << endl;
            maxLen = max(maxLen, root[x] - x + 1);
        }

        return maxLen;
    }
    void unite(int x, int y){
        int root_x = find(x);
        int root_y = find(y);
        root[root_x] = root_y;
        root[x] = root_y;
    }
    int find(int x){
        return (root[x] != x) ? root[x] = find(root[x]) : root[x];
    }
};
