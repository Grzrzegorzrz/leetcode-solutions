#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> m(26, 0);
        int res = 0;

        for(int i : s) {
            m[i-'a']++;
        }

        for(int i : t) {
            m[i-'a']--;
        }

        for(int i : m) {
            res += abs(i);
        }

        return res/2;
    }
};
