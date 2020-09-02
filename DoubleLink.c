//
// Created by qiguang.zhu on 2020/7/31.
//
/**
 * 双向链表 {@link http://data.biancheng.net/view/167.html}
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct DoubleLink {
    struct DoubleLink *pre;
    int data;
    struct DoubleLink *next;
} DoubleLink;

DoubleLink *init(DoubleLink *head) {
    head = (DoubleLink*)malloc(sizeof(DoubleLink));
    head->pre = NULL;
    head->next = NULL;
    head->data = 1;
    DoubleLink *list = head;
    for (int i = 2; i < 6; ++i) {
        DoubleLink *body = (DoubleLink*)malloc(sizeof(DoubleLink));
        body->pre = NULL;
        body->next = NULL;
        body->data = i;

        list->next = body;
        body->pre = list;
        list = list->next;
    }
    return head;
}

void printLink(DoubleLink *link) {
    DoubleLink *tmp = link;
    while (tmp) {
        if (tmp->next == NULL) {
            printf("%d", tmp->data);
        } else {
            printf("%d<->", tmp->data);
        }
        tmp = tmp->next;
    }
}


int main() {
    DoubleLink *head = NULL;
    printLink(init(head));
    return 0;
}

