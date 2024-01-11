#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        std::unordered_map<int, int> record;
        int ways = 0;

        for(int i : nums) {
            record[i]++;
        }

        for(auto it = record.begin(); it != record.end(); it++) {
            if(it->second == 1) return -1;
            
            if(it->second % 3 != 0 ) {
                ways += it->second / 3 + 1;
            } else {
                ways += it->second / 3;
            }
        }

        return ways;
    }
};

//greedy algorithm: always 3 ops
//exception: 4 of same requires 2 ops