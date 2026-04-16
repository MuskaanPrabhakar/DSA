class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int fair = 0;

        int sum1 = 0; // even indices
        int sum2 = 0; // odd indices

        // Step 1: total sums
        for(int i = 0; i < n; i++){
            if(i % 2 == 0) sum1 += nums[i];
            else sum2 += nums[i];
        }

        int left1 = 0; // even sum on left
        int left2 = 0; // odd sum on left

        // Step 2: simulate removal
        for(int i = 0; i < n; i++){

            // remove current element from right
            if(i % 2 == 0) sum1 -= nums[i];
            else sum2 -= nums[i];

            // check fairness
            if(left1 + sum2 == left2 + sum1)
                fair++;

            // move element to left
            if(i % 2 == 0) left1 += nums[i];
            else left2 += nums[i];
        }

        return fair;
    }
};