//
// Created by Administrator on 2021/1/25.
//

#ifndef MAT_LIST_NODE_H
#define MAT_LIST_NODE_H
#include <cstddef>


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


#endif //MAT_LIST_NODE_H
