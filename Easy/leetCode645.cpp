class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        vector<int> res(2,0);

        for(int i = 0; i < n; i++) {
            m[i+1] += 0;
            m[nums[i]]++;
        }

        for(auto& [key, value] : m) {
            if(value == 2) res[0] = key;
            if(value == 0) res[1] = key;
        }

        return res;
    }
};
