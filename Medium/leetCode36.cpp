class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board[0].size();
        int check, curr;
        vector<vector<int>> subBoxes(9, vector<int>(10, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                check = 0;
                curr = board[i][j];
                if(curr == '.') continue;
              
                for(int k = 0; k < n; k++) {
                    if(board[i][k] == curr) check++;
                    if(board[k][j] == curr) check++;

                    if(check > 2) return false;
                }

                int index = i/3*3+j/3;

                if(subBoxes[index][curr-'0']) return false;
                subBoxes[index][curr-'0']++;
            }
        }

        return true;
    }
};
