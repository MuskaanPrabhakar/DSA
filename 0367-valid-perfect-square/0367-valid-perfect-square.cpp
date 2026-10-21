class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num%10==1 || num%10==4 || num%10==9 || num%10==6 || num%10==5 || num%10==0 ){
            int left=1; int right=num;
            while(left<=right){
                int mid=(left+right)/2;
                long long square=(long long)mid*mid;
                if(square==num) return true;
                else if(square<num) left=mid+1;
                else right=mid-1;
            }
        }
        return false;
    }
};