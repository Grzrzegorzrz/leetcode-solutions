class Solution {
public:
    int numSquares(int n) {
        unordered_map<int, int> perfectSquares;
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 1; i <= 100; i++) {
            int curr = pow(i,2);
            if(curr > n) break;
            perfectSquares[curr]++;
            dp[curr] = 1;
        }
        
        for(int i = 2; i < n+1; i++) {
            int currMin = i;
            for(auto& [key, value] : perfectSquares) {
                if(key > i) continue;
                
                int res = 1 + dp[i-key];
                if(res < currMin) currMin = res;
            }

            dp[i] = currMin;
        }

        return dp[n];
    }
};
