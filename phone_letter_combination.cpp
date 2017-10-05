/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    unordered_map<int, string> digitMap{
        {1, ""},
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"},
        {0, " "}
    };
    void generateLetterCombinations(string &digits, int digitPos, 
        char *buffer, vector<string> &result)
    {
        if (digitPos && digitPos >= digits.size()) {
            buffer[digitPos] = 0;
            result.push_back(buffer);
            return;
        }
        int digit = digits[digitPos] - '0';
        auto letters = this->digitMap[digit];
        for (int i = 0; i < letters.size(); i++) {
            buffer[digitPos] = letters[i];
            generateLetterCombinations(digits, digitPos + 1, buffer, result);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        char buffer[digits.size() + 1];
        generateLetterCombinations(digits, 0, buffer, result);
        return result;
    }
};

