class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left;
        vector<int> right;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (pivot > nums[i]) {
                left.push_back(nums[i]);
            }
            else if (pivot < nums[i]) {
                right.push_back(nums[i]);
            }
            else {
                count++;
            }
        }

        for (int i = 0; i < count; i++) {
            left.push_back(pivot);
        }

        left.insert(left.end(), right.begin(), right.end());

        return left;
    }
};