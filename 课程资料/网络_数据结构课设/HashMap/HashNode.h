#ifndef _HASHNODE_H_
#define _HASHNODE_H_

namespace CTSL {
    template <typename K, typename V>
    class HashNode {
    public:
        HashNode() : next(nullptr) {}
        HashNode(K key_, V value_) : next(nullptr), key(key_), value(value_) {}
        ~HashNode() { next = nullptr; }
        const K &getKey() const { return key; }
        void setValue(V value_) { value = value_; }
        const V &getValue() const { return value; }
        HashNode *next;

    private:
        K key;
        V value;
    };

    template <typename K, typename V>
    class HashBucket {
    public:
        HashBucket() : head(nullptr) {}

        ~HashBucket() {
            clear();
        }

        bool find(const K &key, V &value) const {
            HashNode<K, V> *node = head;

            while (node != nullptr) {
                if (node->getKey() == key) {
                    value = node->getValue();
                    return true;
                }
                node = node->next;
            }
            return false;
        }

        void insert(const K &key, const V &value) {
            HashNode<K, V> *prev = nullptr;
            HashNode<K, V> *node = head;

            while (node != nullptr && node->getKey() != key) {
                prev = node;
                node = node->next;
            }

            if (nullptr == node) {
                if (nullptr == head) {
                    head = new HashNode<K, V>(key, value);
                } else {
                    prev->next = new HashNode<K, V>(key, value);
                }
            } else {
                node->setValue(value);
            }
        }

        void erase(const K &key) {
            HashNode<K, V> *prev = nullptr;
            HashNode<K, V> *node = head;

            while (node != nullptr && node->getKey() != key) {
                prev = node;
                node = node->next;
            }

            if (nullptr == node) {
                return;
            } else {
                if (head == node) {
                    head = node->next;
                } else {
                    prev->next = node->next;
                }
                delete node;
            }
        }

        void clear() {
            HashNode<K, V> *prev = nullptr;
            HashNode<K, V> *node = head;
            while (node != nullptr) {
                prev = node;
                node = node->next;
                delete prev;
            }
            head = nullptr;
        }

    private:
        HashNode<K, V> *head;
    };
}

#endif
