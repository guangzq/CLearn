//
// Created by Administrator on 2021/1/1.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1, x = 0;
        vector<int> newVector;
        newVector.resize((r+1)*(b+1));
        while (true) {
            for (int i = l; i <= r; ++i) {
                newVector[x++] = matrix[t][i];
            }
            if (++t > b)break;
            for (int i = t; i <= b; ++i) {
                newVector[x++] = matrix[i][r];
            }
            if (--r < l)break;
            for (int i = r; i >= l; --i) {
                newVector[x++] = matrix[b][i];
            }
            if (--b < t)break;
            for (int i = b; i >= t; --i) {
                newVector[x++] = matrix[i][l];
            }
            if (++l > r)break;
        }
        return newVector;
    }
};

int main() {
    vector<vector<int>> res = {{1, 2,  3,  4},
                                  {5, 6,  7,  8},
                                  {9, 10, 11, 12}};
    Solution solution;
    vector<int> a =  solution.spiralOrder(res);
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << endl;
    }
    return 0;
}

