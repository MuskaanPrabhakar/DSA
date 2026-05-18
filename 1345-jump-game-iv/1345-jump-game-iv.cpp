class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        if (n == 1) return 0;

        // Map value -> all indices having that value
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int idx = q.front();
                q.pop();

                // Reached last index
                if (idx == n - 1) {
                    return steps;
                }

                // Same value jumps
                for (int nextIdx : mp[arr[idx]]) {
                    if (!visited[nextIdx]) {
                        visited[nextIdx] = true;
                        q.push(nextIdx);
                    }
                }

                // Prevent repeated processing
                mp[arr[idx]].clear();

                // i - 1
                if (idx - 1 >= 0 && !visited[idx - 1]) {
                    visited[idx - 1] = true;
                    q.push(idx - 1);
                }

                // i + 1
                if (idx + 1 < n && !visited[idx + 1]) {
                    visited[idx + 1] = true;
                    q.push(idx + 1);
                }
            }

            steps++;
        }

        return -1;
    }
};