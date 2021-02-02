//
// Created by qiguang.zhu on 2021/2/2.
//
#include <iostream>
#include "list_node.h"

using namespace std;

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                cur->next=l1;
                l1=l1->next;
                cur=cur->next;
            } else{
                cur->next=l2;
                l2=l2->next;
                cur=cur->next;
            }
        }
        if (l1 != NULL) {
            cur->next=l1;
        }else if (l2 != NULL) {
            cur->next=l2;
        }
        return dummy->next;
    }
};

/**
 * 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

        示例1：

        输入：1->2->4, 1->3->4
        输出：1->1->2->3->4->4

 * @return
 */
int main() {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(6);
    Solution solution;
    ListNode* listNode = solution.mergeTwoLists(l1, l2);
    while (listNode !=  NULL) {
        cout<<listNode->val<<endl;
        listNode=listNode->next;
    }
    return 0;
}
