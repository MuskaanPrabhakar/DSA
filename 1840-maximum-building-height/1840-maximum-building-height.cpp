class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());

        // Left to right
        for (int i = 1; i < restrictions.size(); i++) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] =
                min(restrictions[i][1],
                    restrictions[i - 1][1] + dist);
        }

        // Right to left
        for (int i = restrictions.size() - 2; i >= 0; i--) {
            int dist = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] =
                min(restrictions[i][1],
                    restrictions[i + 1][1] + dist);
        }

        int ans = 0;

        // Maximum between consecutive restrictions
        for (int i = 1; i < restrictions.size(); i++) {
            int x1 = restrictions[i - 1][0];
            int h1 = restrictions[i - 1][1];

            int x2 = restrictions[i][0];
            int h2 = restrictions[i][1];

            int dist = x2 - x1;
            ans = max(ans,
                      max(h1, h2) + (dist - abs(h1 - h2)) / 2);
        }

        // Buildings after the last restriction
        int lastPos = restrictions.back()[0];
        int lastH = restrictions.back()[1];

        ans = max(ans, lastH + (n - lastPos));

        return ans;
    }
};