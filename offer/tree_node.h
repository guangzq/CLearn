//
// Created by qiguang.zhu on 2021/2/22.
//

#ifndef MAT_TREE_NODE_H
#define MAT_TREE_NODE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#endif //MAT_TREE_NODE_H
