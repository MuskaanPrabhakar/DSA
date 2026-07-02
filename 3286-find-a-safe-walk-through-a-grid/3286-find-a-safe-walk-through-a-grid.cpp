class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        vector<vector<int>> best(m, vector<int>(n, -1));
        queue<tuple<int,int,int>> q;

        q.push({0, 0, startHealth});
        best[0][0] = startHealth;

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [x, y, h] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1)
                return true;

            for (auto &d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                int nh = h - grid[nx][ny];

                if (nh > 0 && nh > best[nx][ny]) {
                    best[nx][ny] = nh;
                    q.push({nx, ny, nh});
                }
            }
        }

        return false;
    }
};