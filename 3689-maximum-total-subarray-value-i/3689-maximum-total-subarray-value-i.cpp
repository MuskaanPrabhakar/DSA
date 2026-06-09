class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        if (nums.size()==1) return 0LL;
        long long mini = INT_MAX; long long maxi= 0;
        for(int i=nums.size()-1; i>0;i--){
            mini = min(mini, (long long)min(nums[i],nums[i-1]));
            maxi = max(maxi, (long long)max(nums[i],nums[i-1]));
        }
        maxi-= mini;
        return maxi*=k;
    }
};
/*class Solution {
public:
    long long maxTotalValue(std::vector<int>& nums, int k) {
        const int64_t min_num = *std::min_element(nums.begin(), nums.end());
        const int64_t max_num = *std::max_element(nums.begin(), nums.end());
        return (max_num - min_num) * k; 
    }
};*/
