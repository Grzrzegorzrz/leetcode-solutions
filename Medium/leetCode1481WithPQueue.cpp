class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int> arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        priority_queue<int, vector<int>, greater<int>> freqPQ;

        int currCount = 1;
        for(int i = 1; i < n; i++) {
            if(arr[i] != arr[i-1]) {
                freqPQ.push(currCount);
                currCount = 1;
            } else {
                currCount++;
            }
        }

        freqPQ.push(currCount);
        int out = freqPQ.size();

        while(k > -1) {
            int curr = freqPQ.top();
            freqPQ.pop();

            k -= curr;
            out--;
        }

        out++;
         
        return out;
    }
};
