class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;

        for (int i = 0; i < s.length(); i++) {
            rotate(s.begin(), s.begin() + 1, s.end());
            if (s == goal) return true;
        }

        return false;
    }
};
/*class Solution {
public:
    bool rotateString(string s, string goal) {
        // Step 1: Length check
        if (s.size() != goal.size()) return false;

        // Step 2: Concatenate
        string doubled = s + s;

        // Step 3: Check substring
        return doubled.find(goal) != string::npos;
    }
};*/
