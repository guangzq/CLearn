//
// Created by qiguang.zhu on 2020/12/24.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        if (matrix.size() == 1 && matrix[0][0] == target) {
            return true;
        }
        for (int i = 0; i < matrix.size(); ++i) {
            if (i + 1 < matrix.size()) {
                if (target > matrix[0][i] && target < matrix[0][i + 1]) {
                    for (int j = 0; j < matrix[i][j]; ++j) {
                        if (target == matrix[i][j]) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {
            {1, 4, 7, 11, 15},
            {2, 5, 8, 12, 19},
            {3, 6, 9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}};
    cout<<"findNumberIn2DArray "<<solution.findNumberIn2DArray(matrix,-1)<<endl;
    return 0;
}