class Solution {
public:
    string removeDuplicateLetters(string s) {
        string k = "";
        vector<int> freq(26, 0);
        vector<bool> used(26, false);

        // count frequency
        for (char c : s) freq[c - 'a']++;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            freq[c - 'a']--;

            if (used[c - 'a']) continue;

            while (!k.empty() && k.back() > c && freq[k.back() - 'a'] > 0) {
                used[k.back() - 'a'] = false;
                k.pop_back();
            }

            k.push_back(c);
            used[c - 'a'] = true;
        }

        return k;
    }
};