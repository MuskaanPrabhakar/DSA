class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k<=nums.size()){
            int index = nums.size()-k;
            std::rotate(nums.begin(), nums.begin() + index, nums.begin() + index + k);
        }
        else if( k%nums.size()!=0){
            k= k%nums.size();
            int index = nums.size()-k;
            std::rotate(nums.begin(), nums.begin() + index, nums.begin() + index + k);
        }
    }
};