class Solution {
    int m, n, ans;
    vector<int> root, rank;
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        // disjoint set
        m = grid.size(), n = grid[0].size();
        int sz = m * n;
        ans = sz;
        root.resize(sz);
        rank.resize(sz, 1);
        iota(root.begin(), root.end(), 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // cout << i << " " << j << endl;
                // cout << ans << endl;
                if (grid[i][j] == '0') ans--;
                else {
                    for (auto [dx, dy] : dirs) {
                        int nextX = i + dx;
                        int nextY = j + dy;
                        if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || grid[nextX][nextY] == '0') continue;
                        uni(encode(i, j), encode(nextX, nextY));
                    }
                }
            }
        }

        return ans;
    }
    int find(int x) {
        if (root[x] == x) return x;
        else return root[x] = find(root[x]);
    }
    void uni(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        if (rank[x] > rank[y]) {
            root[rootY] = rootX;
            rank[x] += rank[y];
        }
        else {
            root[rootX] = rootY;
            rank[y] += rank[x];
        }
        ans--;
    }
    int encode(int x, int y) {
        return x * n + y;
    }
};
