//
// Created by qiguang.zhu on 2021/3/1.
//
#include <iostream>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
    Node *pre, *head;
public:
    Node *treeToDoublyList(Node *root) {
        if (root == nullptr) return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

private:
    void dfs(Node *cur) {
        if (cur == nullptr) return;
        dfs(cur->left);
        if (pre != nullptr) pre->right = cur;
        else head = cur;
        cur->left=pre;
        pre= cur;
        dfs(cur->right);
    }
};

int main() {
    return 0;
}
