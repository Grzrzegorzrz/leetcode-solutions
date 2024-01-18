class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        std::transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c){ return std::tolower(c); });

        int rPtr = n;
        int lPtr = 0;

        while(rPtr > lPtr) {
            if(!isalnum(s[lPtr])) {
                lPtr++;
                continue;
            }
            if(!isalnum(s[rPtr])) {
                rPtr--;
                continue;
            } 

            if(s[lPtr] != s[rPtr]) return false;

            lPtr++;
            rPtr--;
        }

        return true;
    }
};
