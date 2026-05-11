class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector <int> nuu; int k=0;
        for(int i=nums.size()-1; i>=0 ; i--){
                while(nums[i]>=10){
                    k = nums[i]%10;
                    nuu.push_back(k);
                    nums[i]/=10;
                }
                nuu.push_back(nums[i]);
        }
        reverse(nuu.begin(), nuu.end());
        return nuu;
    }
};