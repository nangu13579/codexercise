/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

#include <vector>

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int count = 0;
        decode(s, 0, count);
        return count;
    }

private:
    void decode(string &s, int pos, int &count)
    {
        if (pos >= s.size()) {
            count++;
            return;
        }
        int c = s[pos] - '0';
        if (c == 0) {
            return;
        }
        decode(s, pos + 1, count);
        if (pos + 1 < s.size()) {
            int c2 = 10 * c + s[pos + 1] - '0';
            if (c2 >= 10 && c2 <= 26) {
                decode(s, pos + 2, count);
            }
        }        
    }
};

