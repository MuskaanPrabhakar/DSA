class Solution {
public:
    int br(int n){
        int sum =0;
        while(n>=10){
            sum= sum+(n%10);
            n/=10;
        }
        sum+=n;
        return sum;
    }
    int minElement(vector<int>& nums) {
        int miin=br(nums[0]);
        for(int i=1; i<nums.size(); i++){
            miin = min(miin, br(nums[i]));
        }
        return miin;
    }
};
