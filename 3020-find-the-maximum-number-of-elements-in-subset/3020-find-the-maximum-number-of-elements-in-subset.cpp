class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int x : nums) cnt[x]++;

        int ans = 1;

        // Handle 1 separately
        if (cnt.count(1)) {
            int c = cnt[1];
            ans = max(ans, (c % 2 == 0) ? c - 1 : c);
        }

        for (auto &[x, f] : cnt) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (cnt[cur] >= 2) {
                __int128 nxt = (__int128)cur * cur;

                // Cannot extend further
                if (nxt > 1e18 || !cnt.count((long long)nxt))
                    break;

                len += 2;          // use two copies of cur
                cur = (long long)nxt;
            }

            // Use one copy of cur as the middle element
            if (cnt[cur] > 0)
                ans = max(ans, len + 1);
        }

        return ans;
    }
};