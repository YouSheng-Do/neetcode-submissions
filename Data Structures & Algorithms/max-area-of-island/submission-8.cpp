class Solution {
public:
    vector<int> root, size;
    int m, n;
    int sz;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // union-find
        m = grid.size(), n = grid[0].size();
        sz = m * n;
        root.resize(sz);
        size.assign(sz, 1);
        iota(root.begin(), root.end(), 0);

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}};

        int maxArea = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                maxArea = max(maxArea, 1);
                for (auto [dx, dy] : dirs) {
                    int nextX = dx + i;
                    int nextY = dy + j;
                    if (nextX < 0 || nextY < 0 || nextX >= m || nextY >= n || grid[nextX][nextY] == 0) continue;
                    maxArea = max(maxArea, uni(encode(i, j), encode(nextX, nextY)));
                }
            }
        }

        return maxArea;
    }
    int uni(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return size[rootX];

        if (size[rootX] < size[rootY]) swap(rootX, rootY);

        root[rootY] = rootX;
        size[rootX] += size[rootY];

        return size[rootX];
    }
    int find(int x) {
        if (root[x] == x) return x;
        else return root[x] = find(root[x]);
    }
    int encode(int x, int y) {return x * n + y;}
};
