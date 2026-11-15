class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        //start from int 0 then go to mini l times and then slowly proceed by adding to sum to r and then again start
        int mini=INT_MAX; 
        for(int i=0;i<=nums.size()-l;i++){
            int sum=0;
            for(int j=0;j<r && i+j<nums.size();j++){
                sum+=nums[i+j];
                if(j>=l-1 && sum>0){
                    mini=min(sum,mini);
                }
            }
        }
        if(mini==INT_MAX) return -1;
        return mini;
    }
};