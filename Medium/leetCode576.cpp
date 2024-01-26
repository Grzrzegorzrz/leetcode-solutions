class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int endColumn) {
        int MOD = 1000000000+7;

        if(!maxMove) return 0;

        int grid[m][n][maxMove];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                grid[i][j][0] = 0;
                if(!i) grid[i][j][0]++;
                if(!j) grid[i][j][0]++;
                if(i+1 == m) grid[i][j][0]++;
                if(j+1 == n) grid[i][j][0]++;
            }
        } 

        for(int k = 1; k < maxMove; k++) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    grid[i][j][k] = 0;

                    if(!i) grid[i][j][k]++;
                    else grid[i][j][k] = (grid[i][j][k] + grid[i-1][j][k-1]) % MOD;

                    if(!j) grid[i][j][k]++;
                    else grid[i][j][k] = (grid[i][j][k] + grid[i][j-1][k-1]) % MOD;

                    if(i+1 == m) grid[i][j][k]++;
                    else grid[i][j][k] = (grid[i][j][k] + grid[i+1][j][k-1]) % MOD;
                    
                    if(j+1 == n) grid[i][j][k]++;
                    else grid[i][j][k] = (grid[i][j][k] + grid[i][j+1][k-1]) % MOD;
                }
            }
        }

        return grid[startRow][endColumn][maxMove-1];
    }
};
