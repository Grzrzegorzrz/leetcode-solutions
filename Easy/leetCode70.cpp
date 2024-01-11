#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> waysForStep;
        if(n == 1) return 1;
        waysForStep[0] = 1;
        waysForStep[1] = 2;

        for(int i = 2; i < n; i++){
            waysForStep[i] = waysForStep[i-1] + waysForStep[i-2];
        }

        return waysForStep[n-1];
    }
};