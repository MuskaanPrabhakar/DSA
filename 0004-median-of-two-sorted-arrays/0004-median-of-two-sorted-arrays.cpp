class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size=nums1.size()+nums2.size();
        int idx1=(size/2) -1;
        int element1=-1;
        int idx2=size/2;
        int element2=-1; 
        int i=0;//pointing in nums1
        int j=0;//pointing in nums2
        int k=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                if(k==idx1) element1= nums1[i];
                if(k==idx2) element2=nums1[i];
                i++;
            }
            else{
                if(k==idx1) element1= nums2[j];
                if(k==idx2) element2=nums2[j];
                j++;
            }
            k++;
        }
        while(i<nums1.size()){
            if(k==idx1) element1= nums1[i];
            if(k==idx2) element2=nums1[i];
            i++;
            k++;
        }
        while(j<nums2.size()){
            if(k==idx1) element1= nums2[j];
            if(k==idx2) element2=nums2[j];
            j++;
            k++;
        }
        if(size%2==1) return element2;
        return (element1+element2)/2.0;
    }
};