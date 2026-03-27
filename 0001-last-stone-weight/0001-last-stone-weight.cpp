class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Create max heap
        make_heap(stones.begin(), stones.end());

        while (stones.size() > 1) {
            // Get largest
            pop_heap(stones.begin(), stones.end());
            int first = stones.back();
            stones.pop_back();

            // Get second largest
            pop_heap(stones.begin(), stones.end());
            int second = stones.back();
            stones.pop_back();

            // If not equal, push difference
            if (first != second) {
                stones.push_back(first - second);
                push_heap(stones.begin(), stones.end());
            }
        }

        return stones.empty() ? 0 : stones[0];
    }
};