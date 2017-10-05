/*

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() <= 1) {
            return vector<vector<int> >{nums};
        }
        vector<vector<int> > result;
        vector<int> subArray(nums.begin() + 1, nums.end());
        auto subResult = this->permute(subArray);
        for (auto iter2 = subResult.begin(); iter2 != subResult.end(); ++iter2) {
            vector<int> &array = *iter2;
            for (auto iter3 = array.begin(); iter3 != array.end(); ++iter3) {
                vector<int> permutation(array.begin(), iter3);
                permutation.push_back(nums.front());
                for (auto iter4 = iter3; iter4 != array.end(); ++iter4)
                    permutation.push_back(*iter4);
                result.push_back(permutation);
            }
            vector<int> permutation = array;
            permutation.push_back(nums.front());
            result.push_back(permutation);
        }
        return result;        
    }
};

