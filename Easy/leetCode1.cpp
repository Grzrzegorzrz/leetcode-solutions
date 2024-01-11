#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        int pos;
        int diff;
        bool duplicate = false;

        for(int i = 0; i < nums.size(); i++)
        {
            record[nums[i]]++;
        }

        for(pos = 0; pos < nums.size(); pos++)
        {
            diff = target - nums[pos];
            if(record[diff] == 0) continue;
            if(record[diff] == 1 && nums[pos] == diff) continue;
            if(nums[pos] == diff) duplicate = true;

            break;
        }

        std::vector<int>::iterator diffIt = std::find(nums.begin(), nums.end(), diff);
        if(duplicate) diffIt = std::find(diffIt+1, nums.end(), diff);

        std::vector<int> output;
        output.push_back(pos);
        output.push_back(diffIt - nums.begin());

        return output;

        //find difference (target - num)
        //search if difference exists and is not element
    }
};