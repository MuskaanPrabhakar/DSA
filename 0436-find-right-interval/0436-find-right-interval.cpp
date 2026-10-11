class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ri(n, -1);

        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            int smallestStart = INT_MAX;

            for (int j = 0; j < n; j++) {
                if (intervals[j][0] >= end &&
                    intervals[j][0] < smallestStart) {

                    smallestStart = intervals[j][0];
                    ri[i] = j;
                }
            }
        }

        return ri;
    }
};