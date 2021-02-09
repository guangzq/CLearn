//
// Created by qiguang.zhu on 2021/2/9.
//
#include <iostream>
#include "list_node.h"
using namespace std;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *first = headA;
        ListNode *second = headB;
        while (first != second) {
            if (first != nullptr) {
                first = first->next;
            } else{
                first = headB;
            }
            if (second != nullptr) {
                second = second->next;
            } else{
                second = headA;
            }
        }
        return first;
    }
};
/**
 * 输入两个链表，找出它们的第一个公共节点。
 * @return
 */
int main() {
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(9);

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(8);
    headB->next->next = new ListNode(2);
    headB->next->next->next = new ListNode(9);

    Solution solution;
    ListNode *result = solution.getIntersectionNode(headA, headB);
    while (result != nullptr) {
        cout<<result->val<<endl;
        result = result->next;
    }
    return 0;
}
