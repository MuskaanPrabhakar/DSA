class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        int m = logs.size();
        int q = queries.size();

        vector<int> ans(q, n);

        // Sort logs by time
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        // Store query time along with original index
        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < q; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> freq(n + 1, 0);

        int left = 0;
        int right = 0;
        int activeServers = 0;

        for (int i = 0; i < q; i++) {

            int queryTime = sortedQueries[i].first;
            int originalIndex = sortedQueries[i].second;

            int startTime = queryTime - x;

            // Add logs up to queryTime
            while (right < m && logs[right][1] <= queryTime) {

                int server = logs[right][0];

                if (freq[server] == 0) {
                    activeServers++;
                }

                freq[server]++;
                right++;
            }

            // Remove logs before startTime
            while (left < right && logs[left][1] < startTime) {

                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0) {
                    activeServers--;
                }

                left++;
            }

            ans[originalIndex] = n - activeServers;
        }

        return ans;
    }
};