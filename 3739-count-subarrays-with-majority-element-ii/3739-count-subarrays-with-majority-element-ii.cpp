class Solution {
public:
    struct BIT {
        vector<int> bit;
        int n;

        BIT(int n) {
            this->n = n;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        // Build prefix sums after converting:
        // target -> +1, others -> -1
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        // Coordinate compression of prefix sums
        vector<int> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        BIT bit(vals.size());

        long long ans = 0;

        // Insert prefix sum 0
        int pos = lower_bound(vals.begin(), vals.end(), pref[0]) - vals.begin() + 1;
        bit.update(pos, 1);

        for (int i = 1; i <= n; i++) {
            int curPos = lower_bound(vals.begin(), vals.end(), pref[i]) - vals.begin() + 1;

            // Need previous prefix sums < current prefix sum
            ans += bit.query(curPos - 1);

            bit.update(curPos, 1);
        }

        return ans;
    }
};