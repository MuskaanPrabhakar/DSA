class Solution {
public:
    string maskPII(string s) {
        // EMAIL CASE
        if (s.find('@') != string::npos) {
            string res;
            int at = s.find('@');
            
            res += tolower(s[0]);
            res += "*****";
            res += tolower(s[at - 1]);
            
            for (int i = at; i < s.size(); i++) {
                res += tolower(s[i]);
            }
            
            return res;
        }
        
        // PHONE CASE
        string digits;
        for (char c : s) {
            if (isdigit(c)) digits += c;
        }
        
        int n = digits.size();
        string res;
        
        // country code
        if (n > 10) {
            res += "+";
            for (int i = 0; i < n - 10; i++) res += "*";
            res += "-";
        }
        
        res += "***-***-";
        res += digits.substr(n - 4);
        
        return res;
    }
};