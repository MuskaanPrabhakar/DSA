class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int rem = grid[0][0] % x;

        for (auto &row : grid) {
            for (int val : row) {
                if (val % x != rem) return -1;
                nums.push_back(val);
            }
        }

        sort(nums.begin(), nums.end());

        int median = nums[nums.size() / 2];
        int ans = 0;

        for (int val : nums) {
            ans += abs(val - median) / x;
        }

        return ans;
    }
};