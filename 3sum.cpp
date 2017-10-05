/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <unordered_map>     
#include <algorithm>
#include <set>

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        if (nums.empty()) {
            return vector<vector<int> >();
        }
        sort(nums.begin(), nums.end());
        set<vector<int> > result;
        unordered_map<int, int> seenNums;
        for (int i = 0; i < nums.size() - 1;) {
            for (int j = i + 1; j < nums.size();) {
                auto iter = seenNums.find(nums[i] + nums[j]);
                if (iter != seenNums.end()) {
                    vector<int> found{nums[iter->second], nums[i], nums[j]};
                    result.emplace(found);
                }
                j++;
                while (j < nums.size() && nums[j] == nums[j - 1]) {
                    j++;
                }
            }
            seenNums[-nums[i]] = i;
            i++;
        }
        return vector<vector<int> >{result.begin(), result.end()};
   }
};

