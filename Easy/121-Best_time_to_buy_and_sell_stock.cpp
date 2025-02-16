class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // start, end
        // profit = p[end] - p[start]
        // max
        // p[e-1] > p[e]; e--;

        int buy = prices[0];
        int profit = 0;

        for( int i=1;i<prices.size();i++ ){
            if( prices[i] < buy ) buy=prices[i];
            else if( prices[i] - buy > profit) profit = prices[i] - buy;
        }

        return profit;
    }
};