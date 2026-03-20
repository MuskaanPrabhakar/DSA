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
/*class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size());
        for(int i = (temperatures.size()-1);i>=0;i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = 0;
            }
            else{
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};*/
/*my first ans [inefficient]
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
};*/
