class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(n, -1);
        dp[0] = 0; // start at index 0 with 0 jumps

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = 1LL * nums[i] - nums[j];

                if (dp[j] != -1 && diff >= -target && diff <= target) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};