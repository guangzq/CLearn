//
// Created by Administrator on 2021/1/25.
//
#include <iostream>
#include "list_node.h"

using namespace std;
class Solution {
public:
    ListNode *deleteNode(ListNode *head, int val) {
        if (val == head->val) return head->next;
        ListNode *pre=head;
        ListNode *cur=head->next;
        while (cur != nullptr && cur->val != val) {
            pre = cur;
            cur=cur->next;
        }
        if (cur != nullptr) pre->next = cur->next;
        return head;
    }
};

/**
 * 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。

注意：此题对比原题有改动

示例 1:

输入: head = [4,5,1,9], val = 5
输出: [4,1,9]
解释: 给定你链表中值为5的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

  如何删除一个节点：pre->next=cur->next;
 * @return
 */
int main() {
    ListNode *listNode = new ListNode(4);
    listNode->next = new ListNode(5);
    listNode->next->next = new ListNode(1);
    listNode->next->next->next = new ListNode(9);
    Solution solution;
    listNode = solution.deleteNode(listNode, 1);
    while (listNode != nullptr) {
        cout<<listNode->val<<endl;
        listNode = listNode->next;
    }
    return 0;
}

