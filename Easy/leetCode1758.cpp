#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int ops = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] - '0' == i%2) ops++;
        }
        
        if(ops < s.size() - ops) return ops;
        else return s.size() - ops;
    }
};