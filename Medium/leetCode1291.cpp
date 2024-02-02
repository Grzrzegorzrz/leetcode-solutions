class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int start = 123456789, increment = 111111111;
        vector<int> out;

        for(int i = 0; i < 10; i++) {
            int num = start / pow(10,9-i);
            int currIncre = increment / pow(10,9-i);

            for(int j = 0; j < 9-i+1; j++) {
                if(num >= low && num <= high) out.push_back(num);
                num += currIncre;
            }    
        }

        return out;
    }
};
