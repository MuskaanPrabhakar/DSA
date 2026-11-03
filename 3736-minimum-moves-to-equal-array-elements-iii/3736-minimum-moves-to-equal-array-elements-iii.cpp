class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves=0;
        sort(begin(nums),end(nums));
        int target=nums[nums.size()-1];
        for(int i=0; i<nums.size();i++){
            moves+=abs(nums[i]-target);
        }
        return moves;
    }
};