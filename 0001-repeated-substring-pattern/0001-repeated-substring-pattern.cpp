class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for (int k = 1; k <= n / 2; k++) {
            if (n % k != 0) continue;

            string pattern = s.substr(0, k);
            bool match = true;

            for (int i = k; i < n; i += k) {
                if (s.compare(i, k, pattern) != 0) {
                    match = false;
                    break;
                }
            }

            if (match) return true;
        }

        return false;
    }
};