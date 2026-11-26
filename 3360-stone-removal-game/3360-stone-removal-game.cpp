class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        bool alice=true;
        for(int i=10;n>0;i--){
            if(i%2==0){
                n-=i;
                if(n<0) alice= false;
            }
            else{
                n-=i;
                if(n==0) alice=false;
            }
        }
        return alice;
    }
};