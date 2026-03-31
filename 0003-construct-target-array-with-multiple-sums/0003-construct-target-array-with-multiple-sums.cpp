class Solution {
public:
    bool isPossible(vector<int>& target) {
        long sum = 0;
    for (int x : target) sum += x;

    while (true) {
        auto it = max_element(target.begin(), target.end());

        if (*it == 1 || sum - *it == 1) return true;
        if (sum - *it == 0 || *it <= sum - *it) return false;

        long x = *it % (sum - *it);
        if (x == 0) return false;

        sum = sum - *it + x;
        *it = x;
    }
}
};