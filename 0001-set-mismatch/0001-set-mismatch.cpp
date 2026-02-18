class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2);

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                ans[0] = nums[i];   // duplicate
            }
        }

        // Find missing number
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                ans[1] = i + 1;
                break;
            }
        }

        return ans;
    }
};
