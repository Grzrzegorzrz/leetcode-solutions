class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> out(n);
        int pos = 0;
        int neg = 1;

        for(int i : nums) {
            if(i > 0) {
                out[pos] = i;
                pos+=2;
            }
            else {
                out[neg] = i;
                neg+=2;
            }
        }

        return out;
    }
};
