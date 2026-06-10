class Solution {
public:
    vector<vector<int>> stMax, stMin;
    vector<int> lg;

    long long getValue(int l, int r) {
        int j = lg[r - l + 1];

        int mx = max(stMax[j][l],
                     stMax[j][r - (1 << j) + 1]);

        int mn = min(stMin[j][l],
                     stMin[j][r - (1 << j) + 1]);

        return 1LL * mx - mn;
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        lg.resize(n + 1);
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        int LOG = lg[n] + 1;

        stMax.assign(LOG, vector<int>(n));
        stMin.assign(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) {
            stMax[0][i] = nums[i];
            stMin[0][i] = nums[i];
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                stMax[j][i] = max(
                    stMax[j - 1][i],
                    stMax[j - 1][i + (1 << (j - 1))]
                );

                stMin[j][i] = min(
                    stMin[j - 1][i],
                    stMin[j - 1][i + (1 << (j - 1))]
                );
            }
        }

        using T = array<long long, 3>;
        priority_queue<T> pq;

        for (int l = 0; l < n; l++) {
            long long val = getValue(l, n - 1);
            pq.push({val, l, n - 1});
        }

        long long ans = 0;

        while (k--) {
            auto cur = pq.top();
            pq.pop();

            long long val = cur[0];
            int l = (int)cur[1];
            int r = (int)cur[2];

            ans += val;

            if (r > l) {
                long long nxt = getValue(l, r - 1);
                pq.push({nxt, l, r - 1});
            }
        }

        return ans;
    }
};