class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> prefNum(n + 1, 0);
        vector<int> prefSum(n + 1, 0);
        vector<int> cnt(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefNum[i + 1] = prefNum[i];
            prefSum[i + 1] = prefSum[i];
            cnt[i + 1] = cnt[i];

            if (s[i] != '0') {
                int d = s[i] - '0';
                prefNum[i + 1] = (prefNum[i] * 10 + d) % MOD;
                prefSum[i + 1] += d;
                cnt[i + 1]++;
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int k = cnt[r + 1] - cnt[l];

            long long x = (prefNum[r + 1] -
                           prefNum[l] * pow10[k] % MOD + MOD) % MOD;

            long long sum = prefSum[r + 1] - prefSum[l];

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};
