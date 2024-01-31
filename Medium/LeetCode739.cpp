class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> out(n);
        stack<int> descend;
        descend.push(0);

        for(int i = 1; i < n; i++) {
            while(!descend.empty() && temperatures[i] > temperatures[descend.top()]) {
                out[descend.top()] = i-descend.top();
                descend.pop();
            }

            descend.push(i);
        }

        while(!descend.empty()) {
            out[descend.top()] = 0;
            descend.pop();
        }

        return out;
    }
};
