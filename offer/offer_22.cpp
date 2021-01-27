//
// Created by qiguang.zhu on 2021/1/27.
//
#include "list_node.h"
#include <iostream>

using namespace std;

class Solution {
public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        ListNode *slow = head;
        ListNode *fast = slow;
        int i = 0;
        while (i != k) {
            i++;
            fast = fast->next;
        }
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution solution;
    ListNode *listNode = solution.getKthFromEnd(head, 1);
    while (listNode != NULL) {
        cout << listNode->val << endl;
        listNode = listNode->next;
    }
    return 0;
}