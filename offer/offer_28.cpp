//
// Created by qiguang.zhu on 2021/2/22.
//
#include "tree_node.h"

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        return root == nullptr || recur(root->left, root->right);
    }

private:
    bool recur(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right== nullptr || left->val != right->val) return false;
        return recur(left->left, right->right) && recur(left->right, right->left);
    }
};

int main() {
    return 0;
}

