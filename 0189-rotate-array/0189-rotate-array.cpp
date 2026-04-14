class Solution {
public:
    void rotate(vector<int>& nums, int k) {
            k= k%nums.size();
            if (k == 0) return;
            int index = nums.size()-k;
            std::rotate(nums.begin(), nums.begin() + index, nums.begin() + index + k);
    }
};