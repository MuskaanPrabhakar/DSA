#include <queue>
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;

        for(int i = 0; i < tickets.size(); i++){
            q.push({tickets[i], i});
        }

        int m = 0;

        while(true){
            auto front = q.front();
            q.pop();

            front.first--; // buy ticket
            m++;

            if(front.first == 0 && front.second == k){
                return m;
            }

            if(front.first > 0){
                q.push(front);
            }
        }
    }
};