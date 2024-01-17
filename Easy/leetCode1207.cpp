class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        unordered_set<int> freqOfFreq;

        for(int i = 0; i < n; i++)
            freq[arr[i]]++;
        
        for(auto i : freq) {
            int num = i.second;
            if(freqOfFreq.find(num) != freqOfFreq.end()) return false;
            else freqOfFreq.insert(num);
        }
            
        return true;
    }
};
