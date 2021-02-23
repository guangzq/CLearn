//
// Created by qiguang.zhu on 2021/2/23.
//
#include "tree_node.h"
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode *> queue;
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue.push(root);
        while (!queue.empty()) {
            vector<int> tmp;
            for (int i = queue.size(); i > 0; i--) {
                TreeNode* node = queue.front();
                queue.pop();
                tmp.push_back(node->val);
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

int main() {
    return 0;
}
