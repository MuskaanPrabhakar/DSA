class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int mini= stoi(to_string(nums[0])+to_string(nums[1]));
        for(int i=2;i<nums.size();i+=2){
            mini=min(mini,stoi(to_string(nums[i])+to_string(nums[i+1])));
        }
        return mini;
    }
};