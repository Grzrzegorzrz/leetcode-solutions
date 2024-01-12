#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int sum = 0, firstHalf = 0;

        transform(s.begin(), s.end(), s.begin(), ::tolower);

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') sum++;
        }

        for(int i = 0; i < n/2; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') firstHalf++;
        }

        if(sum == firstHalf*2) return true;
        return false;
    }
};
