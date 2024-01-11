#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int rows[bank.size()];
        memset(rows, 0, sizeof(rows));
        int beams = 0;
        int hold = 0;

        for(int i = 0; i < bank.size(); i++) {
            for(int j : bank[i]) {
                if(j == '1') rows[i]++;
            }
        }

        for(int i = 0; i < bank.size(); i++) {
            if (rows[i]) {
                beams += hold * rows[i];
                hold = rows[i];
            }
        }

        return beams;
    }
};