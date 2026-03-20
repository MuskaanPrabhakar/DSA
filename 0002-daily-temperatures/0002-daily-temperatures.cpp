class Solution {//class bracket start
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {//function bracket start
        vector<int> answer(temperatures.size());
        for(int i=0; i<temperatures.size();i++){//for start
            int j=i+1;
            while(j<temperatures.size()){//while start
                if(temperatures[i]<temperatures[j]){
                    answer[i]=j-i;
                    break;
                } 
                ++j;
                if(j==temperatures.size()) answer[i]=0;
            }//while close
        }//for closed
        return answer;
    }
};