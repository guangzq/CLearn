//
// Created by qiguang.zhu on 2020/12/24.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int i = matrix.size() -1;//行
        int j=0;
        while(i>=0&&j<=matrix[0].size()-1){
            if(matrix[i][j]>target) {i--;}
            else if(matrix[i][j]<target){ j++;}
            else {return true;}
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