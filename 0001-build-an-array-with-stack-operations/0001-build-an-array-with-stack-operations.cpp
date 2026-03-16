class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> arr;
        int i=1, k=0;
            while((i)<=n && k<target.size())
            { 
                arr.push_back("Push");
                if(i==target[k])
                     ++k;
                else 
                   {
                       arr.push_back("Pop");
                }
               i++;
            }
        return arr;    
        }
    };
