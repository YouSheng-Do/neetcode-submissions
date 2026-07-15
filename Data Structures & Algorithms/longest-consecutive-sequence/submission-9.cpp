class Solution {
public:
    unordered_map<int, int> root, size;
    int longestConsecutive(vector<int>& nums) {
        root.reserve(2 * nums.size());
        size.reserve(2 * nums.size());

        for (const int& x : nums) {
            root[x] = x;
            size[x] = 1;
        }
        
        for (const int& x : nums) {
            if (root.count(x + 1)) unite(x, x + 1);
        }

        int maxLen = 0;
        for (const int& x : nums) {
            maxLen = max(maxLen, size[find(x)]);
        }

        return maxLen;
    }
    void unite(int x, int y){
        int root_x = find(x);
        int root_y = find(y);
        if (root_x == root_y) return;

        if (size[root_x] > size[root_y]) swap(root_x, root_y);
        root[root_x] = root_y;
        size[root_y] += size[root_x];
    }
    int find(int x){
        return (root[x] != x) ? root[x] = find(root[x]) : root[x];
    }
};
