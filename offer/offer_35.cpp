//
// Created by qiguang.zhu on 2021/2/7.
//
#include <iostream>
#include <unordered_map>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        unordered_map<Node*,Node*> map;
        while (cur != nullptr) {
            map[cur] = new Node(cur->val);
            cur=cur->next;
        }
        cur = head;
        while (cur != nullptr) {
            map[cur]->next = map[cur->next];
            map[cur->random]->next= map[cur->random];
            cur=cur->next;
        }
        return map[head];
    }
};
int main() {

    return 0;
}


