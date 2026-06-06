class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        vector <int> result(nums.size()); int summ=0;
        for(int i=0; i<nums.size(); i++){
            sum-=nums[i];
            result[i]=abs(sum-summ);
            summ+=nums[i];
        }
        return result;
    }
};