class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n=nums.size()/3; //no. of medians
        long long maxi=0LL;
        sort(begin(nums),end(nums));
        int k=0;
        int i=nums.size()-2;
        while(k!=n){
            maxi+=nums[i];
            k++;
            i-=2;
        }
        return maxi;
    }
};