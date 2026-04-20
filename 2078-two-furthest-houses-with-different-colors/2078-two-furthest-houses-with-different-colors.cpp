class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int i=colors.size()-1;
        for(int j= 0; j<colors.size(); j++){
            if(colors[i]!=colors[j]) return abs(j-i);
        }
    return 0;
    }
};