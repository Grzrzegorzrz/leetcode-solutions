#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        vector<std::unordered_map<int, int>> diffFreq(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if((long)nums[j]-(long)nums[i] > INT_MAX || (long)nums[j]-(long)nums[i]<INT_MIN) continue;
                int diff = nums[j]-nums[i];
                diffFreq[i][diff] += diffFreq[j][diff] + 1;
                sum += diffFreq[j][diff];
            }
        }

        return sum;
    }
};