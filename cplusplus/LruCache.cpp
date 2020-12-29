//
// Created by qiguang.zhu on 2020/12/29.
//
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

/**
 * 实现lru最近最少缓存淘汰算法，最近指的是最近使用的要移动到链表的头部，最少使用的要移到链表的尾部，淘汰尾部
 * 可利用map来映射键值对
 * @return
 */
struct LinkedNode {
    int key, value;
    LinkedNode *prev;
    LinkedNode *next;

    LinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}

    LinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LruCache {
private:
    LinkedNode *head;
    LinkedNode *tail;
    int size, capacity;
    unordered_map<int, LinkedNode *> map;
public:
    LruCache(int _capacity) : capacity(_capacity), size(0) {
        head = new LinkedNode();
        tail = new LinkedNode;
        head->next = tail;
        tail->prev = head;
    }

    /**
     * 获取某个节点并将其移动到head
     * @param key
     * @return
     */
    int get(int key) {
        if (!map.count(key)) {
            return -1;
        }
        LinkedNode *node = map[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (map.count(key)) {
            LinkedNode *node = map[key];
            node->value=value;
            moveToHead(node);
        } else {
            auto *newNode = new LinkedNode(key, value);
            map[key]=newNode;
            addToHead(newNode);
            ++size;
            if (size > capacity) {
                LinkedNode *pNode = removeTail();
                map.erase(pNode->key);
                delete pNode;
                --size;
            }
        }
    }

    /**
     * 思路：只能根据head的指针来移动
     * @param node
     */
    void addToHead(LinkedNode *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(LinkedNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(LinkedNode *node) {
        removeTail();
        addToHead(node);
    }

    LinkedNode *removeTail() {
        LinkedNode *node = tail->prev;
        removeNode(node);
        return node;
    }

    void print(string str) {
        cout<<str<<endl;
        for (auto & i : map) {
            cout<<i.first<<", "<<i.second->value<<endl;
        }
    }
};

int main() {
    auto *lruCache = new LruCache(2);
    lruCache->put(0, 2);
    lruCache->put(1, 6);
    lruCache->put(2, 8);
    lruCache->print("--------new add---------");
    lruCache->put(2, 5);
    lruCache->print("--------old add---------");
}

