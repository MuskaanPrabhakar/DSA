class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int MAXV = *max_element(nums.begin(), nums.end());

        // Smallest Prime Factor sieve
        vector<int> spf(MAXV + 1);
        for (int i = 0; i <= MAXV; i++) spf[i] = i;

        for (int i = 2; i * i <= MAXV; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= MAXV; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        auto isPrime = [&](int x) {
            return x >= 2 && spf[x] == x;
        };

        // prime -> all indices whose nums[idx] divisible by prime
        unordered_map<int, vector<int>> primeToIndices;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            unordered_set<int> usedFactors;

            while (x > 1) {
                int p = spf[x];
                usedFactors.insert(p);

                while (x % p == 0)
                    x /= p;
            }

            for (int p : usedFactors) {
                primeToIndices[p].push_back(i);
            }
        }

        vector<int> dist(n, -1);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        unordered_set<int> usedPrimeTeleport;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int d = dist[i];

            if (i == n - 1)
                return d;

            // adjacent left
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = d + 1;
                q.push(i - 1);
            }

            // adjacent right
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = d + 1;
                q.push(i + 1);
            }

            // teleport
            int val = nums[i];

            if (isPrime(val) && !usedPrimeTeleport.count(val)) {
                usedPrimeTeleport.insert(val);

                for (int nxt : primeToIndices[val]) {
                    if (dist[nxt] == -1) {
                        dist[nxt] = d + 1;
                        q.push(nxt);
                    }
                }
            }
        }

        return -1;
    }
};