class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> tw;

        for (int i = 0; i < queries.size(); i++) {
            for (int j = 0; j < dictionary.size(); j++) {
                
                int diff = 0;

                for (int k = 0; k < queries[i].length(); k++) {
                    if (queries[i][k] != dictionary[j][k]) {
                        diff++;
                        if (diff > 2) break;
                    }
                }

                if (diff <= 2) {
                    tw.push_back(queries[i]);
                    break; // avoid duplicates
                }
            }
        }

        return tw;
    }
};