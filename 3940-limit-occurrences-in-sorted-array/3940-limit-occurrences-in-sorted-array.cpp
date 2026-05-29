class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> freq;

        for (int num : nums) {
            if (freq[num] < k) {
                result.push_back(num);
                freq[num]++;
            }
        }

        return result;
    }
};