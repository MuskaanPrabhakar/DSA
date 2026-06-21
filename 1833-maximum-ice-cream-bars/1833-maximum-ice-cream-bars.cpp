class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int rate=0;
        int i=0; //stores no.of ice cream
        while(rate<=coins && i<costs.size()){
            rate+=costs[i];
            i++;
        }
        if(rate>coins) return i-1;
        return i;
    }
};