#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <string>
#include <vector>
#include <memory>
#include <iostream>

struct CacheNode {
    std::string key;
    int value;
    std::unique_ptr<CacheNode> next;

    CacheNode(const std::string& k, int v) : key(k), value(v), next(nullptr) {}
};

class HashTable {
private:
    static const int BUCKETS = 64;
    std::unique_ptr<CacheNode> table[BUCKETS];

    int hashFunction(const std::string& key) const {
        unsigned long hash = 5381;
        for (char c : key) {
            hash = ((hash << 5) + hash) + c;
        }
        return hash % BUCKETS;
    }

public:
    HashTable() = default;

    void put(const std::string& key, int value) {
        int index = hashFunction(key);
        CacheNode* current = table[index].get();
        
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next.get();
        }

        auto newNode = std::make_unique<CacheNode>(key, value);
        newNode->next = std::move(table[index]);
        table[index] = std::move(newNode);
    }

    int* get(const std::string& key) {
        int index = hashFunction(key);
        CacheNode* current = table[index].get();
        
        while (current != nullptr) {
            if (current->key == key) return &(current->value);
            current = current->next.get();
        }
        return nullptr;
    }
};

#endif
