class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mx = 1; // first element must be 1
        for (int i = 1; i < arr.size(); i++) {
            mx = min(arr[i], mx + 1);
        }
        return mx;
    }
};