class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0; // Pointer for nums1
        int j = 0; // Pointer for nums2
        
        // Loop until one of the pointers runs out of bounds
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                return nums1[i]; // Found the smallest common element
            }
            else if (nums1[i] < nums2[j]) {
                i++; // Move nums1 pointer forward
            }
            else {
                j++; // Move nums2 pointer forward
            }
        }
        
        return -1; // No common element found
    }
};