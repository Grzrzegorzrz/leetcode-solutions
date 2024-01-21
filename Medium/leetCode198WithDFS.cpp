class Solution {
public:
    int memo[101];
    int dfs(vector<int>& nums, int i) {
        if(i == nums.size()-1) return nums[i];          //end case
        if(i > nums.size()-1) return 0;
        if(memo[i] != -1) return memo[i];               //memoization

        memo[i] = max(dfs(nums, i+1), dfs(nums, i+2) + nums[i]);  //return greater of: dfs of next house, or dfs of next next house + current house value
        return memo[i];
    }

    int rob(vector<int>& nums) {
        memset(memo,-1,sizeof(memo));
        return dfs(nums, 0);
    }
};
