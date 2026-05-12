class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort by (minimum - actual) descending
        sort(tasks.begin(), tasks.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return (a[1] - a[0]) > (b[1] - b[0]);
             });

        int energy = 0, ans = 0;

        for (auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];

            // If current energy is insufficient, add more
            if (energy < minimum) {
                ans += (minimum - energy);
                energy = minimum;
            }

            // Complete the task
            energy -= actual;
        }

        return ans;
    }
};