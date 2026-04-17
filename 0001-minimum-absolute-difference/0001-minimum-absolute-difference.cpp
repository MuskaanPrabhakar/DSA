class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        vector<vector<int>> dif;
        int mini = arr[1]-arr[0];
        dif.push_back({arr[0], arr[1]});
        for (int i = 2; i < arr.size(); i++) {
            int diff = arr[i] - arr[i-1];

            if (diff < mini) {
                mini = diff;
                dif.clear(); // remove old pairs
                dif.push_back({arr[i-1], arr[i]});
            }
            else if (diff == mini) {
                dif.push_back({arr[i-1], arr[i]});
            }
        }

        return dif;
    }
};