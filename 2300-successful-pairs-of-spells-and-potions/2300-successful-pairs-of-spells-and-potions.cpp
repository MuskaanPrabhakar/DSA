class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>result(spells.size(),potions.size());
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            int l=0; int r=potions.size();
            while(l<=r && l<potions.size() && r>=0){
                int mid=(l+r)/2;
                long long k=1ll*spells[i]*potions[mid];
                if(k<success) l=mid+1;
                else r=mid-1;
            }
            result[i]-=l;
        }
        return result;
    }
};
