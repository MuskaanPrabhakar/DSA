class Solution {
public:
    long long solve(vector<int>& Astart, vector<int>& Adur,
                    vector<int>& Bstart, vector<int>& Bdur) {

        int m = Bstart.size();

        vector<pair<int,int>> rides;
        for (int i = 0; i < m; i++) {
            rides.push_back({Bstart[i], Bdur[i]});
        }

        sort(rides.begin(), rides.end());

        vector<int> start(m);
        vector<long long> prefDur(m), suffStartDur(m);

        for (int i = 0; i < m; i++) {
            start[i] = rides[i].first;
        }

        prefDur[0] = rides[0].second;
        for (int i = 1; i < m; i++) {
            prefDur[i] = min(prefDur[i - 1],
                             (long long)rides[i].second);
        }

        suffStartDur[m - 1] =
            (long long)rides[m - 1].first + rides[m - 1].second;

        for (int i = m - 2; i >= 0; i--) {
            suffStartDur[i] =
                min(suffStartDur[i + 1],
                    (long long)rides[i].first + rides[i].second);
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < (int)Astart.size(); i++) {

            long long finishFirst =
                (long long)Astart[i] + Adur[i];

            int pos =
                upper_bound(start.begin(),
                            start.end(),
                            finishFirst)
                - start.begin();

            // Bstart <= finishFirst
            if (pos > 0) {
                ans = min(ans,
                          finishFirst + prefDur[pos - 1]);
            }

            // Bstart > finishFirst
            if (pos < m) {
                ans = min(ans,
                          suffStartDur[pos]);
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long ans = min(
            solve(landStartTime, landDuration,
                  waterStartTime, waterDuration),

            solve(waterStartTime, waterDuration,
                  landStartTime, landDuration)
        );

        return (int)ans;
    }
};