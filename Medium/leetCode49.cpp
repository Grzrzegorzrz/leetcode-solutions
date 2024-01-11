#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<vector<string>> res;
        res.reserve(n);

        unordered_map<string, vector<string>> m;
        m.reserve(n);

        for(string& i : strs) {
            string temp = i;
            sort(i.begin(), i.end());

            m[i].push_back(temp);
        }

        for(auto& [key, value] : m){
            res.push_back(value);
        }
        
        return res;
    }
};