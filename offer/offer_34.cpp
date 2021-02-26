//
// Created by qiguang.zhu on 2021/2/26.
//
#include <iostream>
#include <vector>
#include "tree_node.h"

using namespace std;
class Solution {
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        recur(root, sum);
        return res;
    }

private:
    void recur(TreeNode* root, int sum) {
        if (root == nullptr) return;
        path.push_back(root->val);
        sum -= root->val;
        if (sum == 0 && root->left == nullptr && root->right == nullptr) {
            res.push_back(path);
        }
        recur(root->left, sum);
        recur(root->right, sum);
        path.pop_back();
    }
};
int main() {
    return 0;
}

