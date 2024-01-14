#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        if(n != word2.length()) return false;
        
        vector<int> letters1(26, 0);
        vector<int> letters2(26, 0);

        for(int i = 0; i < n; i++) {
            letters1[word1[i]-'a']++;
            letters2[word2[i]-'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(letters1[i] && !letters2[i]) return false;
        }

        sort(letters1.begin(), letters1.end());
        sort(letters2.begin(), letters2.end());

        return letters1 == letters2;
    }
};
