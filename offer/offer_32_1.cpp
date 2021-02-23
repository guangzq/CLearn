//
// Created by qiguang.zhu on 2021/2/23.
//
#include <vector>
#include "tree_node.h"
#include <queue>//看下双端队列
using namespace std;
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> queue;
        if (root != nullptr) return res;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode *node = queue.front();
            queue.pop();
            res.push_back(node->val);
            if (node->left) {
                queue.push(node->left);
            }
            if (node->right) {
                queue.push(node->right);
            }
        }
        return res;
    }
};
int main() {
    return 0;
}
