class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> arr;
        int i = 1, k = 0;
        //we could also use target.back() instead of n which would stop action if last number was directly accessed 
        while ((i) <= n && k < target.size()) {
            arr.push_back("Push");
            if (i == target[k])
                ++k;
            else {
                arr.push_back("Pop");
            }
            i++;
        }
        return arr;
    }
};
