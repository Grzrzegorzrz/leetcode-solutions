#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> m;
        vector<vector<int>> res;
        vector<int> a0;
        vector<int> a1;

        for(auto& i : matches) {
            m[i[1]]++;
            m[i[0]] += 0;
        }

        for(auto& [key, value] : m) {
            if(!value) a0.push_back(key);
            else if(value == 1) a1.push_back(key);
        }

        sort(a0.begin(), a0.end());
        sort(a1.begin(), a1.end());

        res.push_back(a0);
        res.push_back(a1);

        return res;
    }
};
