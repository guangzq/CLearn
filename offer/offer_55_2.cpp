//
// Created by qiguang.zhu on 2021/3/3.
//
#include <iostream>
#include "tree_node.h"
#include <math.h>

using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (root == nullptr) return false;
        return abs(maxD(root->left) - maxD(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int maxD(TreeNode *root) {
        if (root == nullptr) return 0;
        return max(maxD(root->left),maxD(root->right)) + 1;
    }
};

int main() {
    return 0;
}

