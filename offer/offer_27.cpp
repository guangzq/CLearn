//
// Created by qiguang.zhu on 2021/2/22.
//
#include "tree_node.h"

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};

int main() {
    return 0;
}

