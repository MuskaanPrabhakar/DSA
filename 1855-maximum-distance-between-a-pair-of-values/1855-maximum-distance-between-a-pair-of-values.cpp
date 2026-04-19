class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int mx =0; int i=0;
        for(int j=0; j<nums2.size() && i<nums1.size() ;j++){
            if(nums1[i]<=nums2[j]){
                mx= max(mx,j-i);
            }
            else i++;
        }  
        return mx; 
    }
};