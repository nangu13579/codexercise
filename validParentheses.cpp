/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/

#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> seenParens;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(' || c == '{' || c == '[') {
                seenParens.push(c);
            } else {
                if (seenParens.empty()) {
                    return false;
                }
                char t = seenParens.top();
                if ((t == '(' && c == ')') ||
                    (t == '{' && c == '}') ||
                    (t == '[' && c == ']')) {
                    seenParens.pop();
                } else {
                    return false;
                }
            }
        }
        return seenParens.empty();
    }
};

