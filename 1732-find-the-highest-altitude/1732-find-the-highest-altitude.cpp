class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0, k=0;
        for(int i=0;i<gain.size();i++){
            k+=gain[i];
            maxi=max(maxi,k);
        }
        return maxi;
    }
};