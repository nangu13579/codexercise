/**
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        return matchCharAt(s, 0, p, 0);
    }
private:
    bool matchCharAt(const string &s, int sPos, const string &p, int pPos) {
        if (sPos >= s.size() && pPos >= p.size()) {
            return true;
        }
        if (pPos + 1 < p.size() && p[pPos + 1] == '*') {
            if (sPos < s.size() && (p[pPos] == '.' || s[sPos] == p[pPos])) {
                if (matchCharAt(s, sPos+1, p, pPos)) {
                    return true;
                }
            }
            return matchCharAt(s, sPos, p, pPos + 2);
        } else {
            if (sPos < s.size() && pPos < p.size()
                && (p[pPos] == '.' || s[sPos] == p[pPos])) {
                return matchCharAt(s, sPos+1, p, pPos+1);
            } else {
                return false;
            }
        }
    }
};

