class Solution {
public: 
    int minimumLength(string s) {
        int n = s.length();
        if(n == 1) return 1;
        
        int lPtr = 0, rPtr = n-1;
        while(lPtr <= rPtr) {
            int curr = s[lPtr];
            if(s[lPtr] == s[rPtr]) {
                while(s[lPtr] == curr && lPtr <= rPtr)
                    lPtr++;
                while(s[rPtr] == curr && lPtr <= rPtr)
                    rPtr--;
            } else {
                return rPtr-lPtr+1;
            }

            if(lPtr == rPtr) return 1;
        }

        return 0;
    }
};
