class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        
        // dp[i][j][c] = max score reaching (i,j) with cost = c
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1, -1))
        );
        
        dp[0][0][0] = 0; // start
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    
                    if (dp[i][j][c] == -1) continue;
                    
                    // Move RIGHT
                    if (j + 1 < n) {
                        int val = grid[i][j + 1];
                        int newCost = c + (val > 0 ? 1 : 0);
                        
                        if (newCost <= k) {
                            dp[i][j + 1][newCost] = max(
                                dp[i][j + 1][newCost],
                                dp[i][j][c] + val
                            );
                        }
                    }
                    
                    // Move DOWN
                    if (i + 1 < m) {
                        int val = grid[i + 1][j];
                        int newCost = c + (val > 0 ? 1 : 0);
                        
                        if (newCost <= k) {
                            dp[i + 1][j][newCost] = max(
                                dp[i + 1][j][newCost],
                                dp[i][j][c] + val
                            );
                        }
                    }
                }
            }
        }
        
        // Find best score at destination
        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[m - 1][n - 1][c]);
        }
        
        return ans;
    }
};