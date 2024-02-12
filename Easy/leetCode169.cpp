//O(n) solution

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int half = n/2;
        unordered_map<int, int> freq;

        for(int i : nums) {
            freq[i]++;
            if(freq[i] > half)
                return i;
        }

        return 0;
    }
};

//O(1) space solution
/*
 *class Solution {
 *public:
 *    int majorityElement(vector<int>& nums) {
 *        int n = nums.size();
 *        
 *        sort(nums.begin(), nums.end());
 *
 *        return nums[n/2];
 *    }
 *};
 */
