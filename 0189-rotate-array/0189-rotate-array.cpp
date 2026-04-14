class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // handle large k

        if (k == 0) return;

        int index = n - k;
        std::rotate(nums.begin(), nums.begin() + index, nums.end());
    }
};