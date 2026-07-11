# Advanced Data Structure Processing System ⚡

A high-performance, modern C++ In-Memory Cache Engine engineered with a custom Chaining Hash Table and an automated LRU (Least Recently Used) eviction policy. Built completely from scratch without STL container overhead to achieve ultra-low microsecond latency.

## 📊 Core Architecture & Modern Enhancements
* **Memory Management:** Zero raw `new/delete` leaks by migrating to modern C++ smart pointers (`std::unique_ptr`).
* **Algorithmic Mechanics:** Custom DJB2 hashing algorithm integrated with dynamic doubly-linked lists for $O(1)$ eviction capability.
* **Latency Benchmarks:** High-resolution sub-microsecond micro-benchmarking engine execution.

## 🗂️ Project Structure
```text
├── include/
│   ├── HashTable.hpp      # Smart-pointer-driven chaining hash map
│   └── LRUCache.hpp       # Real-time cache eviction orchestration core
├── src/
│   └── main.cpp           # High-precision benchmark runtime loop
└── README.md
