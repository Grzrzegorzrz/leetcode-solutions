class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;

        for(int i : arr)
            freq[i]++;

        vector<int> vec;
        vec.reserve(freq.size());

        for(auto& [key, value] : freq) {
            vec.push_back(value);
        }

        sort(vec.begin(), vec.end());

        int removed = 0;
        int out = freq.size();

        for(int i : vec) {
            removed += i;
            if(removed > k) break;
            out--;
        }

        return out;
    }
};
