class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int current;

        if(n == 1) return nums[0];

        int prevPrev = nums[0], prev = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {
            current = max(prevPrev + nums[i], prev);
            prevPrev = prev;
            prev = current;
        }

        return prev;
    }
};
