class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0;
        int right = n;

        while (left < right) {
            int mid = (left + right) / 2;

            if (citations[mid] >= n - mid) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return n - left;
    }
};