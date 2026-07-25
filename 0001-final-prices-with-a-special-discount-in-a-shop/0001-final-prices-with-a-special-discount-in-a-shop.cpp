class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> answer(prices.size());

        for(int i = 0; i < prices.size(); i++) {
            int j = i + 1;

            while(j < prices.size()) {
                if(prices[j] <= prices[i]) {
                    answer[i] = prices[i] - prices[j];
                    break;
                }
                j++;
            }

            // if no discount found
            if(j == prices.size()) {
                answer[i] = prices[i];
            }
        }

        return answer;
    }
};
