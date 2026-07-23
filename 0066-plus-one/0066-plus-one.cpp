class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.back()<9) digits[digits.size()-1]= digits.back()+1;
        else 
        {
             int i= digits.size()-1;
             digits.push_back(0);
             digits[i]=1;
             while(i>0 && digits[i]==1 && digits[i-1]==9 ){
                 digits[i-1]=1;
                 digits[i]=0;
                 i--;
             }
             if(i>0){
                 digits.pop_back();
                 digits[i]=0;
                 digits[i-1]= digits[i-1]+1;
             }
        }
        return digits;
    }
};
