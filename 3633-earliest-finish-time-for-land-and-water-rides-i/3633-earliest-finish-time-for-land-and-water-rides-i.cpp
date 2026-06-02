class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int ans = INT_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Land -> Water
                int finishLand = landStartTime[i] + landDuration[i];
                int finishBoth1 = max(finishLand, waterStartTime[j]) + waterDuration[j];

                // Water -> Land
                int finishWater = waterStartTime[j] + waterDuration[j];
                int finishBoth2 = max(finishWater, landStartTime[i]) + landDuration[i];

                ans = min(ans, min(finishBoth1, finishBoth2));
            }
        }

        return ans;
    }
};