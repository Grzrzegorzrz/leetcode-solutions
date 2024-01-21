class Solution {
public:
    bool isValid(string s) {
        stack<int> brackets;

        for(int i : s) {
            if(i == '(' || i == '{' || i == '[') {
                brackets.push(i);
                continue;
            }
            if(brackets.empty()) return false;
            if(i == ')' && brackets.top() != '(') return false;
            if(i == '}' && brackets.top() != '{') return false;
            if(i == ']' && brackets.top() != '[') return false;
            brackets.pop();
        }

        if(brackets.empty()) return true;
        return false;
    }
};
