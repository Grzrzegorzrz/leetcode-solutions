class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> lowest;

        for(int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i-1];
            if(diff > 0) lowest.push(diff);

            if(lowest.size() > ladders) {
                bricks -= lowest.top();
                lowest.pop();
            }

            if(bricks < 0) return i-1;
        }

        return n-1;
    }
};
