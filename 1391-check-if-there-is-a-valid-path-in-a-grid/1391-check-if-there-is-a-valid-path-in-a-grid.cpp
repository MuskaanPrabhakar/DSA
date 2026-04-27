class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Directions: left, right, up, down
        vector<pair<int,int>> dirs = {{0,-1},{0,1},{-1,0},{1,0}};

        // For each street type, allowed directions
        vector<vector<int>> typeDirs = {
            {},             // 0 unused
            {0,1},          // type 1: left, right
            {2,3},          // type 2: up, down
            {0,3},          // type 3: left, down
            {1,3},          // type 4: right, down
            {0,2},          // type 5: left, up
            {1,2}           // type 6: right, up
        };

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        q.push({0,0});
        vis[0][0] = true;

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if(x == m - 1 && y == n - 1) return true;

            int type = grid[x][y];

            for(int d : typeDirs[type]) {
                int nx = x + dirs[d].first;
                int ny = y + dirs[d].second;

                if(nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny])
                    continue;

                // Opposite direction
                int opp;
                if(d == 0) opp = 1;      // left -> right
                else if(d == 1) opp = 0; // right -> left
                else if(d == 2) opp = 3; // up -> down
                else opp = 2;           // down -> up

                int nextType = grid[nx][ny];

                // Check if next cell connects back
                for(int nd : typeDirs[nextType]) {
                    if(nd == opp) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                        break;
                    }
                }
            }
        }

        return false;
    }
};