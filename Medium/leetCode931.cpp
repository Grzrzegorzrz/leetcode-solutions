class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 1) return matrix[0][0];

        int dp[n][n];
        int hold;

        for(int i = 0; i < n; i++) 
            dp[0][i] = matrix[0][i];
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                hold = matrix[i][j];
                dp[i][j] = dp[i-1][j] + hold;

                if(j > 0 && dp[i-1][j-1] + hold < dp[i][j])
                    dp[i][j] = dp[i-1][j-1] + hold;

                if(j < n-1 && dp[i-1][j+1] + hold < dp[i][j])
                    dp[i][j] = dp[i-1][j+1] + hold;
            }
        }

        sort(dp[n-1], dp[n-1] + n);

        return dp[n-1][0];
    }
};
