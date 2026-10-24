class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> expectedNums;
        expectedNums.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=expectedNums[expectedNums.size()-1]) expectedNums.push_back(nums[i]);
        }
        int k= expectedNums.size();
        nums=expectedNums;
        return k;
    }
};