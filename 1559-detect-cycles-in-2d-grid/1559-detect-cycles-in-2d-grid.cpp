class Solution {
public:
    int m, n;
    vector<vector<int>> vis;
    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid, char ch) {
        vis[x][y] = 1;
        
        for (auto &d : dirs) {
            int nx = x + d.first;
            int ny = y + d.second;
            
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (grid[nx][ny] != ch) continue;
            
            // Don't go back to parent cell
            if (nx == px && ny == py) continue;
            
            // If already visited and not parent => cycle found
            if (vis[nx][ny]) return true;
            
            if (dfs(nx, ny, x, y, grid, ch)) return true;
        }
        
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis.assign(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1, grid, grid[i][j]))
                        return true;
                }
            }
        }
        
        return false;
    }
};