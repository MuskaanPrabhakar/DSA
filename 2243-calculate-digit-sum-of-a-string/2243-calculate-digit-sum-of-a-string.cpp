class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size()<=k) return s;
        string ans="";
        for(int i=0;i<s.size();i+=k){
            int sum=0; int j=0;
            while(j<k && i+j<s.size()){
                sum+=s[i+j] -'0';
                j++;
            }
            ans+=to_string(sum);
        }
        ans= digitSum(ans,k);
        return ans;
   }
};