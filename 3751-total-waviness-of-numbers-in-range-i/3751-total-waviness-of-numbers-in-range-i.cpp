class Solution {
public:
    struct Node {
        long long cnt;
        long long sum;
    };

    string s;
    Node dp[12][3][11][11];
    bool vis[12][3][11][11];

    Node dfs(int pos, bool tight, int len, int a, int b) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][len][a][b]) {
            return dp[pos][len][a][b];
        }

        int lim = tight ? s[pos] - '0' : 9;

        long long cnt = 0;
        long long sum = 0;

        for (int d = 0; d <= lim; d++) {
            bool ntight = tight && (d == lim);

            if (len == 0) {
                if (d == 0) {
                    Node child = dfs(pos + 1, ntight, 0, 10, 10);
                    cnt += child.cnt;
                    sum += child.sum;
                } else {
                    Node child = dfs(pos + 1, ntight, 1, d, 10);
                    cnt += child.cnt;
                    sum += child.sum;
                }
            }
            else if (len == 1) {
                Node child = dfs(pos + 1, ntight, 2, a, d);
                cnt += child.cnt;
                sum += child.sum;
            }
            else {
                int add =
                    ((b > a && b > d) || (b < a && b < d));

                Node child = dfs(pos + 1, ntight, 2, b, d);

                cnt += child.cnt;
                sum += child.sum + 1LL * add * child.cnt;
            }
        }

        Node res = {cnt, sum};

        if (!tight) {
            vis[pos][len][a][b] = true;
            dp[pos][len][a][b] = res;
        }

        return res;
    }

    long long solve(int n) {
        if (n < 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, true, 0, 10, 10).sum;
    }

    int totalWaviness(int num1, int num2) {
        return (int)(solve(num2) - solve(num1 - 1));
    }
};