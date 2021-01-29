//
// Created by qiguang.zhu on 2021/1/28.
//
#include "list_node.h"
#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        while (cur != NULL) {
            ListNode* tmp = cur->next;
            cur->next=pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution solution;
    ListNode* reverseListNode = solution.reverseList(head);
    while (reverseListNode != nullptr) {
        cout<<reverseListNode->val<<endl;
        reverseListNode = reverseListNode->next;
    }
    return 0;
}

