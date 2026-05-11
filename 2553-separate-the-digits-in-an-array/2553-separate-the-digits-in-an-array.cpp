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
/*class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans ;
        
        for( auto &it : nums ){
            
            string tmp = to_string(it);
            
            for( auto &s : tmp ) ans.push_back(s-'0');
            
        }
        
        return ans ;
    }
};*/
