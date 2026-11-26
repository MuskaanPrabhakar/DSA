class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n,0);
        int x=0;
        for(int i=0;i<n;i++){
            ans[x]=nums[i];
            ans[x+1]=nums[n+i];
            x+=2;
        }
        return ans;
    }
};