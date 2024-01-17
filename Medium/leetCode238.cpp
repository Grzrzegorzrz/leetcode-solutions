class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> out;
        int prefix[n];
        int postfix[n];

        prefix[0] = nums[0];
        postfix[n-1] = nums[n-1];
        
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] * nums[i];
            postfix[n-i-1] = postfix[n-i] * nums[n-i-1];
        }

        for(int i = 0; i < n; i++) {
            int res;
            if(i > 0) res = prefix[i-1];
            if(i < n-1) {
                if(res) res *= postfix[i+1];
                else res = postfix[i+1];
            }

            out.push_back(res);
        }

        return out;
    }
};
