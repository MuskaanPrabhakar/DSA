class Solution {
public:
    using ll = long long;

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<ll> pos;
        
        // Convert each boundary point to 1D perimeter position
        for (auto &p : points) {
            ll x = p[0], y = p[1];

            if (y == 0) pos.push_back(x);                          // bottom
            else if (x == side) pos.push_back(side + y);          // right
            else if (y == side) pos.push_back(3LL * side - x);    // top
            else pos.push_back(4LL * side - y);                   // left
        }

        sort(pos.begin(), pos.end());

        ll low = 0, high = 2LL * side, ans = 0;

        while (low <= high) {
            ll mid = (low + high) / 2;

            if (canChoose(pos, side, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }

    bool canChoose(vector<ll>& pos, int side, int k, ll d) {
        int n = pos.size();
        ll perimeter = 4LL * side;

        // duplicate array for circular handling
        vector<ll> arr = pos;
        for (int i = 0; i < n; i++) arr.push_back(pos[i] + perimeter);

        // try each point as starting point
        for (int start = 0; start < n; start++) {
            int cnt = 1;
            ll last = arr[start];

            for (int i = start + 1; i < start + n && cnt < k; i++) {
                if (arr[i] - last >= d) {
                    cnt++;
                    last = arr[i];
                }
            }

            // check circular last-first gap
            if (cnt >= k && perimeter - (last - arr[start]) >= d)
                return true;
        }

        return false;
    }
};
/*uint32_t dists[15000];
uint16_t nxt[15000];

class Solution {
public:
    int maxDistance(int s, vector<vector<int>>& points, int k) {
        const uint64_t n = points.size(), perim = 4UL * s;

        for (uint i = 0; i < n; i++) {
            uint64_t x = points[i][0], y = points[i][1];
            dists[i] = (x == 0 || y == s) ? perim - x - y : x + y;
        }

        sort(dists, dists + n);

        const auto check = [&](uint64_t x) -> bool {
            for (uint i = 0, r = 0; i < n; i++) {
                r = max(r, i + 1);
                while (r < n && dists[r] < dists[i] + x) r++;
                nxt[i] = r;
            }
            uint64_t maxreach = dists[n - 1] + perim - (k - 1) * x;
            auto limit = perim - x;

            for (uint i = 0; i < n && dists[i] <= maxreach; i++) {
                uint j = i;
                for (uint r = k - 1; r > 0 && j != n; r--) {
                    j = nxt[j];
                }
                if (j != n && dists[j] - dists[i] <= limit) return true;
            }
            return false;
        };

        uint64_t lo = 1, hi = perim / k;
        while (lo < hi) {
            auto x = (lo + hi + 1) / 2;
            if (check(x))
                lo = x;
            else
                hi = x - 1;
        }
        return hi;
    }
}; best optimal answer*/
