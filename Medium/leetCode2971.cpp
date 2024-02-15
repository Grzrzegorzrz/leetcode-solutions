//prefix sum soluton
/*
class Solution {
    public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        long prefix[n];
        memset(prefix, 0, sizeof(prefix));
        sort(nums.begin(), nums.end());

        long sum = -1;
        prefix[0] = nums[0];
        prefix[1] = nums[1] + nums[0];
        for(int i = 2; i < n; i++) {
            prefix[i] = nums[i] + prefix[i-1];
            if(nums[i] < prefix[i-1]) sum = prefix[i];
        }

        return sum;
    }
};

//prefix sum simplified solution
class Solution {
    public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long sum = -1;
        long prev = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] < prev) sum = prev + nums[i];
            prev += nums[i];
        }

        return sum;
    }
};
