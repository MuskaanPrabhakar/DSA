class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lower, upper;
        int count = 0;
        for (int i= word.length()-1; i>=0; i--) {
            if (islower(word[i])) {
                lower.insert(word[i]);
            } else if(!lower.count(tolower(word[i]))) {
                upper.insert(tolower(word[i]));
            }
            else if(upper.count(tolower(word[i]))){
                upper.erase(tolower(word[i]));
            }
        }
        for (char ch : lower) {
            if (upper.count(ch)) {
                count++;
            }
        }

        return count;
    }
};