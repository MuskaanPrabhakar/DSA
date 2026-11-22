class Solution {
public:
    int minRange(int a, int b, int c) {
        if(a==b && b==c) return 0;
        else{
            int maxi=max(a,max(b,c));
            int min1=min(a,min(b,c));
            int min2=a+b+c-maxi-min1;
            return min((maxi-min1),(max(min1+min2,max(min1,min2))-min1));
        }
    }
};