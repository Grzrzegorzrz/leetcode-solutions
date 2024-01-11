#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int seqLength[nums.size()];
        seqLength[0] = 1;
        int localHigh;
        int highest = 1;

        for(int i = 1; i < nums.size(); i++) {
            localHigh = 0;

            for(int j = 0; j < i; j++) {
                if(seqLength[j] > localHigh && nums[j] < nums[i]) localHigh = seqLength[j];
            }
            
            seqLength[i] = localHigh + 1;
            if(seqLength[i] > highest) highest = seqLength[i];
        }

        return highest;
    }
};