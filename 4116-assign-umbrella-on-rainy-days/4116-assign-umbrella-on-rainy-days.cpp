class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int alice=0; int bob=0;
        vector<string> result(rain.size(),"");
        for(int i=0; i<rain.size();i++){
            if(rain[i]==0) result[i]+="None";
            else if(rain[i]==1){
                if((i+1)<rain.size() && rain[i+1]==1 && alice<=bob){
                    result[i]+="Alice";
                    alice++;
                }
                else{
                    result[i]+="Bob";
                    bob++;
                }
            }
        }
        return result;
    }
};