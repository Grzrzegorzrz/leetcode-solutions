#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> LongSeq;
        LongSeq.reserve(nums.size());
        bool newElement;

        for(int i : nums) {
            newElement = true;
            for(int j = 0; j < LongSeq.size(); j++) {
                if(i <= LongSeq[j]) {
                    LongSeq[j] = i;
                    newElement = false;
                    break;
                }
            }
            if(newElement) LongSeq.push_back(i);
        }

        return LongSeq.size();
    }
};

//patience sorting attempt