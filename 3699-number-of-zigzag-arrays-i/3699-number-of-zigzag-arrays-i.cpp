class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const long long MOD = 1e9 + 7;
        int m = r - l + 1;

        vector<long long> up(m + 1), down(m + 1);

        // length = 2
        for (int x = 1; x <= m; x++) {
            up[x] = x - 1;
            down[x] = m - x;
        }

        // build lengths 3 ... n
        for (int len = 3; len <= n; len++) {

            vector<long long> newUp(m + 1), newDown(m + 1);

            long long pref = 0;
            for (int y = 1; y <= m; y++) {
                newUp[y] = pref;
                pref = (pref + down[y]) % MOD;
            }

            long long suff = 0;
            for (int y = m; y >= 1; y--) {
                newDown[y] = suff;
                suff = (suff + up[y]) % MOD;
            }

            up = move(newUp);
            down = move(newDown);
        }

        long long ans = 0;
        for (int x = 1; x <= m; x++) {
            ans = (ans + up[x] + down[x]) % MOD;
        }

        return ans;
    }
};