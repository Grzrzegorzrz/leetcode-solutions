#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<tuple<int, int, int>> blocks;
    unordered_map<int, int> cache;

    int dfs(int i) {
        if(i == n) return 0;
        if(cache[i] != 0) return cache[i];
        
        int j = lower_bound(blocks.begin(), blocks.end(), get<1>(blocks[i]), 
            [](tuple<int, int, int> const &t1, int value) {
                return get<0>(t1) < value; 
            }
        ) - blocks.begin();

        int disclude = dfs(i+1);
        int include = get<2>(blocks[i]) + dfs(j);

        if(disclude > include) {
            cache[i] = disclude;
            return disclude;
        }
        cache[i] = include;
        return include;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        blocks.reserve(n);

        for(int i = 0; i < n; i++) {
            blocks.push_back(tuple<int, int, int>(startTime[i], endTime[i], profit[i]));
        }

        sort(blocks.begin(), blocks.end(),
            [](tuple<int, int, int> const &t1, tuple<int, int, int> const &t2) {
                return get<0>(t1) < get<0>(t2); 
            }
        );
        
        return dfs(0);
    }
};