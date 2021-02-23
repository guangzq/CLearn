//
// Created by qiguang.zhu on 2021/2/23.
//
#include "tree_node.h"
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode *> queue;
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue.push(root);
        vector<int> res_tmp;
        int left_to_right=1;
        while (!queue.empty()) {
            vector<int> tmp;
            for (int i = queue.size(); i > 0; i--) {
                TreeNode* node = queue.front();
                queue.pop();
                tmp.push_back(node->val);
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            if (left_to_right % 2 == 0) {
                reverse(tmp.begin(), tmp.end());
                res.push_back(tmp);
            }else {
                res.push_back(tmp);
            }
            left_to_right++;
        }
        return res;
    }
};

int main() {
    return 0;
}
