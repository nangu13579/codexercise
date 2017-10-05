/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size())
            return "";
        unordered_map<char, int> require;
        for (int i = 0; i < t.size(); i++)
            require[t[i]]++;
        vector<int> matchIndices;
        int foundLeft = -1, foundLen;
        int matchCount = 0;
        for (int i = 0; i < s.size(); i++) {
            auto itr = require.find(s[i]);
            if (itr == require.end())
                continue;
            itr->second--;
            //cout << "c=" << itr->first << " count=" << itr->second << endl;
            if (itr->second >= 0)
                matchCount++;
            //cout << "matchCount=" << matchCount << endl;
            if (matchCount == t.size()) {
                if (matchCount == 1) {
                    return s.substr(i, 1);
                }
                while (!matchIndices.empty()) {
                    int left = matchIndices.front();
                    if (foundLeft < 0 || i - left + 1 < foundLen) {
                        foundLeft = left;
                        foundLen = i - left + 1;
                        //cout << "found=" << found << endl;
                    }
                    matchIndices.erase(matchIndices.begin());
                    require[s[left]]++;
                    if (require[s[left]] > 0) {
                        matchCount--;
                        break;
                    }
                } // eof while
            }                                  
            matchIndices.push_back(i);
        } // eof for
        return foundLeft < 0 ? "" : s.substr(foundLeft, foundLen);        
    }
};

