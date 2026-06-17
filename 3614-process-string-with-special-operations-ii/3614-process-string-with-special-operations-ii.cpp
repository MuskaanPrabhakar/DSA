class Solution {
public:
    char processStr(string s, long long k) {
        vector<long long> len(s.size());
        long long cur = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z')
                len[i] = cur;

            else if (s[i] != '*' && s[i] != '#' && s[i] != '%')
                len[i] = ++cur;

            else if (s[i] == '*')
                cur = max(0LL, cur - 1), len[i] = cur;

            else if (s[i] == '#')
                cur = min((long long)4e18, cur * 2), len[i] = cur;

            else if (s[i] == '%')
                len[i] = cur;
        }

        if (k >= cur) return '.';

        for (int i = s.size() - 1; i >= 0; i--) {
            long long before = (i == 0 ? 0 : len[i - 1]);

            if (s[i] >= 'A' && s[i] <= 'Z')
                continue;

            if (s[i] != '*' && s[i] != '#' && s[i] != '%') {
                if (k == before) return s[i];
            }

            else if (s[i] == '#') {
                k %= before;
            }

            else if (s[i] == '%') {
                k = before - 1 - k;
            }

            else if (s[i] == '*') {
                if (k == before) return '.';
            }
        }

        return '.';
    }
};