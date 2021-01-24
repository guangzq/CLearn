//
// Created by Administrator on 2021/1/24.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    stack<int> stack;
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        while (head != NULL) {
            stack.push(head->val);
            head = head->next;
        }
        int length = stack.size();
        for (int i = 0; i < length; ++i) {
            int top = stack.top();
            stack.pop();
            result.push_back(top);
        }
        return result;
    }
};

/**
 * 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
 * @return
 */
int main() {
    Solution solution;
    auto *listNode = new ListNode(1);
    listNode->next = new ListNode(3);
    listNode->next->next = new ListNode(2);
    vector<int> vector = solution.reversePrint(listNode);
    for (int i = 0; i < vector.size(); ++i) {
        cout<<vector[i]<<endl;
    }
    return 0;
}