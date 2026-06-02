class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());

        int mincost = 0;

        for (int i = cost.size() - 1; i >= 0; i -= 3) {
            mincost += cost[i];
            if (i - 1 >= 0) {
                mincost += cost[i - 1];
            }
        }

        return mincost;
    }
};
/*class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());

        int mincost = 0;

        for (int i = 0; i < cost.size(); i++) {
            if ((i + 1) % 3 != 0) {
                mincost += cost[i];
            }
        }

        return mincost;
    }
};*/
