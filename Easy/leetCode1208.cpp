class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        int lPtr, rPtr;
        bool pal;

        for(string str : words) {
            lPtr = 0, rPtr = str.length()-1;
            pal = true;

            while(lPtr < rPtr) {
                if(str[lPtr] != str[rPtr]) {
                    pal = false;
                    break;
                }
                lPtr++;
                rPtr--;
            }

            if(pal) return str;
        }

        return "";
    }
};
