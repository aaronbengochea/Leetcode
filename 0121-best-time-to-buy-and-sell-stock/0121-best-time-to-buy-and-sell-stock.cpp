class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        if(prices.size() == 1){
            return maxProfit;
        }

        int currentMin = prices[0];
        for(int i = 1; i < prices.size(); i++){
            maxProfit = max(maxProfit, prices[i] - currentMin);
            currentMin = min(currentMin, prices[i]);
        }

        return maxProfit;
    }
};

/* 
Brute force O(n^2)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        if(prices.size() == 1){
            return maxProfit;
        }

        for(int i = 0; i < prices.size() - 1; i++){
            for(int j = i + 1; j < prices.size(); j++){
                if(prices[i] < prices[j] && ((prices[j] - prices[i]) > maxProfit)){
                    maxProfit = prices[j] - prices[i];
                }
            }
        }

        return maxProfit;
    }
*/