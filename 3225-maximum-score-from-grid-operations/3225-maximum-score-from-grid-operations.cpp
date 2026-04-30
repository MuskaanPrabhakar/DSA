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
/*best optimal ans 
class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        long long preSum[2][n + 1];
        preSum[0][0] = preSum[1][0] = 0;
        for (int i = 0; i < n; i++)
            preSum[0][i + 1] = preSum[0][i] + grid[i][0];

        // dp[col][nextBlack][decr-eq/incr]
        long long dp[2][n + 1][2];
        memset(dp, 0, sizeof(dp));
        int prev = 0, curr = 1;
        for (int col = 0; col < n - 1; col++) {
            for (int i = 0; i < n; i++)
                preSum[curr][i + 1] = preSum[curr][i] + grid[i][col + 1];
            
            long long preMax = dp[prev][0][1];
            for (int nextBlack = 1; nextBlack <= n; nextBlack++) {
                dp[curr][nextBlack][0] = dp[curr][nextBlack][1]
                    = max(dp[prev][nextBlack][0], preMax + preSum[prev][nextBlack]);
                preMax = max(preMax, dp[prev][nextBlack][1] - preSum[prev][nextBlack]);
            }

            long long sufMax = dp[prev][n][0] + preSum[curr][n];
            for (int nextBlack = n - 1; nextBlack > 0; nextBlack--) {
                dp[curr][nextBlack][0] = max(dp[curr][nextBlack][0],
                                                sufMax - preSum[curr][nextBlack]);
                sufMax = max(sufMax, dp[prev][nextBlack][0] + preSum[curr][nextBlack]);
            }

            dp[curr][0][0] = sufMax;
            dp[curr][0][1] = max(dp[prev][0][0], dp[prev][n][0]);
            swap(prev, curr);
        }

        return *max_element((long long*)dp[prev], (long long*)dp[prev] + (n + 1) * 2);
    }
};*/
