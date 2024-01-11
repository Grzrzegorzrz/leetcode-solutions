#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> freq;
        vector<pair<int, int>> common(n);
        vector<int> res;
        res.reserve(k);

        for(int& i : nums) {
            freq[i]++;
        }

        for(auto& [key, value] : freq ) {
            common.push_back(pair<int, int>{key, value});
        }

        sort(common.begin(), common.end(), 
            [](pair<int,int>& a, pair<int,int>& b){
                return a.second > b.second;
            }
        );

        for(int i = 0; i < k; i++) {
            res.push_back(common[i].first);
        }
        
        return res;
    }
};