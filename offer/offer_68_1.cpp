//
// Created by qiguang.zhu on 2021/3/4.
//
#include <iostream>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        while (root != nullptr) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            } else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }else {
                break;
            }
        }
        return root;
    }
};

int main() {
    return 0;
}

