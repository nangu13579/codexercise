/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        const int maxLen = 240;
        char result[maxLen + 1];
        memset(result, '0', maxLen);
        result[maxLen] = 0;
        char multiTable[10][maxLen + 1];
        memset(multiTable, 0, sizeof(multiTable));
        int offset = 0;
        for (int i = num2.size() - 1; i >= 0; i--) {
            char *prod = multiTable[num2[i] - '0'];
            if (prod[0] == 0) {
                memset(prod, '0', maxLen);
                prod[maxLen] = 0;
                if (num2[i] - '0') {
                    for (int j = num1.size() - 1; j >=0; j--) {
                        int index = maxLen - num1.size() + j;
                        int tmp = (num2[i] - '0') * (num1[j] - '0') + (prod[index] - '0');
                        prod[index] = (tmp % 10) + '0';
                        prod[index - 1] += tmp / 10;
                    } // eof j
                }
            }
            for (int j = num1.size(); j >= 0; j--) {
                int index = maxLen - num1.size() - 1 + j;
                //cout << "index=" << index << " offset=" << offset << endl;
                int tmp = (result[index - offset] - '0') + (prod[index] - '0');
                result[index - offset] = '0' + (tmp % 10);
                result[index - offset - 1] += tmp / 10;
            }
            //cout << "SUM: " << result << endl;
            offset++;
        } // eof i
        int first = 0;
        while (result[first] == '0') {
            first++;
        }
        if (first == maxLen) {
            first--;
        }
        return result + first;
    }
};
