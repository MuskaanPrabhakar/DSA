class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        stack<int> st;
        
        st.push(start);

        while (!st.empty()) {
            int i = st.top();
            st.pop();

            // Skip invalid or already visited indices
            if (i < 0 || i >= n || visited[i]) {
                continue;
            }

            // Found a zero
            if (arr[i] == 0) {
                return true;
            }

            visited[i] = true;

            // Push next possible jumps
            st.push(i + arr[i]);
            st.push(i - arr[i]);
        }

        return false;
    }
};