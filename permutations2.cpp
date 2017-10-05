/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() <= 1) {
            return vector<vector<int> >{nums};
        }
        set<vector<int> > result;
        vector<int> subArray(nums.begin() + 1, nums.end());
        auto subResult = this->permuteUnique(subArray);
        for (auto iter2 = subResult.begin(); iter2 != subResult.end(); ++iter2) {
            vector<int> &array = *iter2;
            for (auto iter3 = array.begin(); iter3 != array.end(); ++iter3) {
                vector<int> permutation(array.begin(), iter3);
                permutation.push_back(nums.front());
                for (auto iter4 = iter3; iter4 != array.end(); ++iter4)
                    permutation.push_back(*iter4);
                result.insert(permutation);
            }
            vector<int> permutation = array;
            permutation.push_back(nums.front());
            result.insert(permutation);
        }
        vector<vector<int> > resultArray(result.begin(), result.end());
        return resultArray;
        
    }
};

