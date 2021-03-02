//
// Created by qiguang.zhu on 2021/3/2.
//
#include <iostream>
#include "list_node.h"
#include "tree_node.h"

using namespace std;
class Solution {
    int k,res;
public:
    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return res;
    }

private:
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->right);
        if (k == 0) return;
        if (--k == 0)  res = root->val;
        dfs(root->left);
    }
};
int main() {
    return 0;
}

