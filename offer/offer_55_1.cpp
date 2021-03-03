//
// Created by qiguang.zhu on 2021/3/3.
//
#include <iostream>
#include "tree_node.h"
#include <math.h>

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main() {
    return 0;
}

