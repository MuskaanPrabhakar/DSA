class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return 0LL;

        // prefix sums by column
        long long pref[101][102] = {};
        for (int c = 0; c < n; c++) {
            for (int r = 0; r < n; r++) {
                pref[c][r + 1] = pref[c][r] + grid[r][c];
            }
        }

        // gain[col][L][C][R] compressed:
        // score of column col if left=L, cur=C, right=R
        static long long gain[100][101][101];
        for (int col = 0; col < n; col++) {
            for (int C = 0; C <= n; C++) {
                for (int M = 0; M <= n; M++) {
                    if (M <= C) gain[col][C][M] = 0;
                    else gain[col][C][M] = pref[col][M] - pref[col][C];
                }
            }
        }

        const long long NEG = -(1LL << 60);
        static long long dp[101][101], ndp[101][101];

        // initialize column 0
        for (int h0 = 0; h0 <= n; h0++) {
            for (int h1 = 0; h1 <= n; h1++) {
                dp[h0][h1] = gain[0][h0][max(0, h1)];
            }
        }

        for (int col = 1; col <= n - 2; col++) {

            for (int i = 0; i <= n; i++)
                for (int j = 0; j <= n; j++)
                    ndp[i][j] = NEG;

            for (int a = 0; a <= n; a++) {
                for (int b = 0; b <= n; b++) {

                    long long cur = dp[a][b];
                    if (cur == NEG) continue;

                    // split by c <= a and c > a
                    for (int c = 0; c <= a; c++) {
                        long long val = cur + gain[col][b][a];
                        if (val > ndp[b][c]) ndp[b][c] = val;
                    }

                    for (int c = a + 1; c <= n; c++) {
                        long long val = cur + gain[col][b][c];
                        if (val > ndp[b][c]) ndp[b][c] = val;
                    }
                }
            }

            memcpy(dp, ndp, sizeof(dp));
        }

        long long ans = 0;

        // last column
        for (int a = 0; a <= n; a++) {
            for (int b = 0; b <= n; b++) {
                ans = max(ans, dp[a][b] + gain[n - 1][b][a]);
            }
        }

        return ans;
    }
};