class Solution {
public:
    struct Node {
        long long cnt;
        long long sum;
    };

    string s;
    Node memo[20][3][11][11];
    bool vis[20][3][11][11];

    Node dfs(int pos, bool tight, int len, int a, int b) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][len][a][b]) {
            return memo[pos][len][a][b];
        }

        int limit = tight ? s[pos] - '0' : 9;

        long long totalCnt = 0;
        long long totalSum = 0;

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (len == 0) {
                if (d == 0) {
                    auto child = dfs(pos + 1, ntight, 0, 10, 10);
                    totalCnt += child.cnt;
                    totalSum += child.sum;
                } else {
                    auto child = dfs(pos + 1, ntight, 1, d, 10);
                    totalCnt += child.cnt;
                    totalSum += child.sum;
                }
            }
            else if (len == 1) {
                auto child = dfs(pos + 1, ntight, 2, a, d);

                totalCnt += child.cnt;
                totalSum += child.sum;
            }
            else {
                int add =
                    ((b > a && b > d) ||
                     (b < a && b < d));

                auto child = dfs(pos + 1, ntight, 2, b, d);

                totalCnt += child.cnt;
                totalSum += child.sum + child.cnt * add;
            }
        }

        Node ans = {totalCnt, totalSum};

        if (!tight) {
            vis[pos][len][a][b] = true;
            memo[pos][len][a][b] = ans;
        }

        return ans;
    }

    long long solve(long long n) {
        if (n < 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, true, 0, 10, 10).sum;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};