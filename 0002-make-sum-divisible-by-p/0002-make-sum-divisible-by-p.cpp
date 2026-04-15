class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total += x;
        
        int target = total % p;
        if (target == 0) return 0;
        
        unordered_map<int, int> seen;
        seen[0] = -1;  // prefix mod → index
        
        long long prefix = 0;
        int res = nums.size();
        
        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p;
            
            int needed = (prefix - target + p) % p;
            
            if (seen.find(needed) != seen.end()) {
                res = min(res, i - seen[needed]);
            }
            
            // store latest index for this prefix mod
            seen[prefix] = i;
        }
        
        return res == nums.size() ? -1 : res;
    }
};