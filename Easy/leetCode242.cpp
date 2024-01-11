#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> freq;
        int n = s.length();
        freq.reserve(n);

        if(n != t.length()) return false;

        for(int i = 0; i < n; i++) {
            freq[s[i]]++;
            freq[t[i]]--;
        }

        for(auto& [key, value] : freq) {
            if(value != 0) return false;
        }
        return true;
    }
};