class Solution {
public:
    int maximum69Number(int num) {
        string len = to_string(num);

        for (int i = 0; i < len.size(); i++) {
            if (len[i] == '6') {
                len[i] = '9';
                break;
            }
        }

        return stoi(len);
    }
};