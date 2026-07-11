#ifndef LRUCACHE_HPP
#define LRUCACHE_HPP

#include "HashTable.hpp"
#include <string>

struct ListNode {
    std::string key;
    ListNode* prev;
    ListNode* next;
    ListNode(const std::string& k) : key(k), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    int size;
    HashTable storage;
    ListNode* head;
    ListNode* tail;

    void moveToHead(ListNode* node) {
        if (node == head) return;
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        if (node == tail) tail = node->prev;
        node->next = head;
        node->prev = nullptr;
        if (head) head->prev = node;
        head = node;
        if (!tail) tail = head;
    }

    void removeTail() {
        if (!tail) return;
        ListNode* oldTail = tail;
        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            head = tail = nullptr;
        }
        delete oldTail;
    }

public:
    explicit LRUCache(int cap) : capacity(cap), size(0), head(nullptr), tail(nullptr) {}

    void write(const std::string& key, int value) {
        int* existing = storage.get(key);
        if (existing) {
            *existing = value;
            return;
        }

        if (size >= capacity) {
            if (tail) {
                storage.put(tail->key, -1); 
                removeTail();
                size--;
            }
        }

        storage.put(key, value);
        ListNode* newNode = new ListNode(key);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    int read(const std::string& key) {
        int* val = storage.get(key);
        if (!val || *val == -1) return -1;
        return *val;
    }

    ~LRUCache() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

#endif
