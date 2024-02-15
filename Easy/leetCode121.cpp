class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min = prices[0], diff = 0;
      
        for(int i = 1; i < n; i++) {
            int curr = prices[i];
            if(curr < min) min = curr;
            else if(curr - min > diff) diff = curr - min;
        }

        return diff;
    }
};
