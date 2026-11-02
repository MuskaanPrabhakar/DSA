class Solution {
public:
    int minMoves2(vector<int>& nums) {
        nth_element(begin(nums),begin(nums)+(nums.size()/2),end(nums));
        int mid=nums[nums.size()/2];
        int moves=0;
        for(int i=0;i<nums.size()/2;i++){
            moves+=abs(nums[i]-mid);
            moves+=abs(nums[nums.size()-i-1]-mid);
        }
        return moves;
    }
};