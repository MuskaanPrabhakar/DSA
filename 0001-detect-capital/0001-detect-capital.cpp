class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();

        // Case 1: all lowercase
        if (islower(word[0])) {
            for (int i = 1; i < n; i++) {
                if (!islower(word[i])) return false;
            }
            return true;
        }

        // Now first letter is uppercase

        // Case 2: all uppercase
        bool allUpper = true;
        for (int i = 1; i < n; i++) {
            if (!isupper(word[i])) {
                allUpper = false;
                break;
            }
        }
        if (allUpper) return true;

        // Case 3: only first uppercase, rest lowercase
        for (int i = 1; i < n; i++) {
            if (!islower(word[i])) return false;
        }

        return true;
    }
};