class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length(), n2 = text2.length();
        int dp[n1+1][n2+1];
        memset(dp, 0, sizeof(dp));

        for(int i = n1-1; i > -1; i--) {
            for(int j = n2-1; j > -1; j--) {
                if(text1[i] == text2[j]) dp[i][j] = dp[i+1][j+1] + 1;
                else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            } 
        }

        return dp[0][0];
    }
};
