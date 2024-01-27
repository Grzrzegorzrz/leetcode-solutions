class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int lPtr = 0, rPtr = n-1;

        while(numbers[lPtr] + numbers[rPtr] != target) {
            if(numbers[lPtr] + numbers[rPtr] < target)
                lPtr++;
            else 
                rPtr--;
        }

        return {lPtr + 1, rPtr + 1};
    }
};
