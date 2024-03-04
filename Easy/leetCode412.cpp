class Solution {
public:
    vector<string> fizzBuzz(int n) {
        map<int, string> fBuzz;
        fBuzz[3] = "Fizz";
        fBuzz[5] = "Buzz";
        vector<string> out(n, "");

        for(int i = 1; i <= n; i++) {
            for(auto& [key, value] : fBuzz) {
                if(i % key == 0) out[i-1] += value;
            }

            if(out[i-1] == "") out[i-1] = to_string(i);
        }

        return out;
    }
};
