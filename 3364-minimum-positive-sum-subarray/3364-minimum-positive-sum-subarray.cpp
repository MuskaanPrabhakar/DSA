class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        //start from int 0 then go to mini l times and then slowly proceed by adding to sum to r and then again start
        int mini=INT_MAX; 
        for(int i=0;i<=nums.size()-l;i++){
            int j=0;
            int sum=0;
            while(i+j<nums.size() && j<l){
                sum+=nums[i+j];
                j++;
            }
            if(sum>0){
                mini=min(mini,sum);
            }
            while(i+j<nums.size() && j<r){
                sum+=nums[i+j];
                if(sum>0){
                    mini=min(mini,sum);
                }
                j++;
            }
        }
        if(mini==INT_MAX) return -1;
        return mini;
    }
};