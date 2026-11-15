
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int M = 1e9 + 7;
        long long odd = 0, even = 1;
        long long ans = 0;
        int parity = 0;

        for (int x : arr) {
            parity = (parity + x) % 2;

            if (parity == 1) {
                ans = (ans + even) % M;
                odd++;
            } else {
                ans = (ans + odd) % M;
                even++;
            }
        }

        return ans;
    }
};
