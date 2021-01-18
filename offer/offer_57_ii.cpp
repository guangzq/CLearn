//
// Created by Administrator on 2021/1/18.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int left = 1, right = 1;
        int sum = 0;
        vector<vector<int>> res;
        while (left <= target / 2) {
            if (target >sum) {
                sum += right;
                right++;
            } else if (target < sum) {
                sum -= left;
                left++;
            } else {
                vector<int> aRes;
                for (int i = left; i <right; ++i) {
                    aRes.push_back(i);
                }
                res.push_back(aRes);
                sum-=left;
                left++;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> vector = solution.findContinuousSequence(9);
    return 0;
}
