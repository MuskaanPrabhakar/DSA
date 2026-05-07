class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n), suffMin(n);

        prefMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }

        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        vector<int> ans(n);

        int start = 0;

        for (int i = 0; i < n - 1; i++) {

            // if all left values < all right values,
            // component breaks here
            if (prefMax[i] < suffMin[i + 1]) {

                int mx = prefMax[i];

                for (int j = start; j <= i; j++) {
                    ans[j] = mx;
                }

                start = i + 1;
            }
        }

        // last component
        int mx = prefMax[n - 1];

        for (int j = start; j < n; j++) {
            ans[j] = mx;
        }

        return ans;
    }
};