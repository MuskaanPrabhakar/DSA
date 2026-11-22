class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        if(nums.size()==1) return 1;
        else{
            int d=0;
            if(nums[0]>=nums[1]) d++;
            if(nums[nums.size()-1]>=nums[nums.size()-2])d++;
            for(int i=1;i+1<nums.size();i++){
                double x=(nums[i-1]+nums[i+1])/2.0;
                if(nums[i]>=x) d++;
            }
            return d++;
        }
    }
};