#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include <functional>
#include <iostream>

#include "HashNode.h"

constexpr size_t HASH_SIZE_DEFAULT = 999983;
namespace CornMing {

    template <typename K, typename V, typename F = std::hash<K> >
    class HashMap {
    public:
        HashMap(size_t hashSize_ = HASH_SIZE_DEFAULT) : hashSize(hashSize_) 
        {
            hashTable = new CTSL::HashBucket<K, V>[hashSize];
        }

        ~HashMap() { delete[] hashTable; }

        HashMap(const HashMap &) = delete;
        HashMap(HashMap &&) = delete;
        HashMap &operator=(const HashMap &) = delete;
        HashMap &operator=(HashMap &&) = delete;

        bool find(const K &key, V &value) const {
            size_t hashValue = hashFn(key) % hashSize;
            return hashTable[hashValue].find(key, value);
        }

        void insert(const K &key, const V &value) {
            size_t hashValue = hashFn(key) % hashSize;
            hashTable[hashValue].insert(key, value);
        }

        void erase(const K &key) {
            size_t hashValue = hashFn(key) % hashSize;
            hashTable[hashValue].erase(key);
        }

        void clear() {
            for (size_t i = 0; i < hashSize; i++) {
                (hashTable[i]).clear();
            }
        }

    private:
        CTSL::HashBucket<K, V> *hashTable;
        F hashFn;
        const size_t hashSize;
    };
}  // namespace CornMing
#endif
