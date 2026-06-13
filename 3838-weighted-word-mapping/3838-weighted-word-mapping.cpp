class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int ascii=122; //ascii output z 
        int asc=97; //ascii output a
        int n;//for storing index for weights
        int sum=0; //for storing index of string char
        string s="";
        for(int i=0; i<words.size();i++){
            for(int k=0; k<words[i].size();k++){
                n=(int)words[i][k] -asc;
                sum+=weights[n];
            }
            sum%=26;
            sum=ascii-sum;
            s+=(char)sum;
            sum=0;
        }
        return s;
    }
};