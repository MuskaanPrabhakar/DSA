class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(cost1+cost2> costBoth){
            if(need1>need2){
                long long min1=1LL *costBoth*need2;
                need1-=need2;
                if(cost1>costBoth) return min1+=(1LL *costBoth*need1);
                else return min1+=(1LL *cost1*need1);
            }
            else if(need1<need2){
                long long min1=1LL *costBoth*need1;
                need2-=need1;
                if(cost2>costBoth) return min1+=(1LL *costBoth*need2);
                else return min1+=(1LL *cost2*need2);
            }
            else{
                long long min1=1LL *costBoth*need1;
                return min1;
            }  
        }
        else{
            long long min1= 1LL *cost1*need1+1LL *cost2*need2;
            return min1;
        } 
    }
};