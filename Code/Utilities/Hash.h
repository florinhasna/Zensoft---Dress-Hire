#ifndef _HASH_HPP_
#define _HASH_HPP_

#include <optional>
#include <vector>

template <typename K, typename V>
class LinearProbingHash {
private:
  std::optional<K>* key_list;
  V* values;
  size_t qty;
  size_t capacity;

public:
  LinearProbingHash() {
    capacity = 100;
    qty = 0;
    key_list = new std::optional<K>[capacity];
    values = new V[capacity];
    for (size_t i = 0; i < capacity; ++i) {
      key_list[i] = {};
      values[i] = 0;
    }
  }

  ~LinearProbingHash() {
    delete[] key_list;
    delete[] values;
  }

  size_t size() {
    return qty;
  }

  bool empty() {
    return qty == 0;
  }

  bool contains(K key) {
    return key_list[pos(key)].has_value();
  }

  size_t pos(K key) {
    size_t index = std::hash<K>{}(key) % capacity;
    while (key_list[index].has_value() && *key_list[index] != key)
      index = (index + 1) % capacity;
    return index;
  }

  void put(K key, V value) {
    size_t index = pos(key);

    if (!key_list[index].has_value()) {
      key_list[index] = std::optional<K>{key};
      ++qty;
    }

    values[index] = value;

    if (qty >= capacity/2)
      resize(2*capacity);
  }

  V get(K key) {
    size_t index = pos(key);
    return *key_list[index];
  }

  V& operator[](K key) {
    if (!contains(key))
      put(key, V());

    size_t index = pos(key);
    return values[index];
  }

  void resize(size_t newsize) {
    std::optional<K>* oldkeys = key_list;
    V* oldvalues = values;
    size_t old_capacity = capacity;

    key_list = new std::optional<K>[newsize];
    values = new V[newsize];
    for (size_t i = 0; i < newsize; ++i) {
      key_list[i] = {};
      values[i] = 0;
    }

    capacity = newsize;
    qty = 0;

    for (size_t i = 0; i < old_capacity; ++i) {
      if (oldkeys[i].has_value())
        put(*oldkeys[i], oldvalues[i]);
    }

    delete[] oldkeys;
    delete[] oldvalues;
  }

  void remove(K key) {
    size_t index = pos(key);
    if (!key_list[index].has_value())
      return;

    // remove this item
    key_list[index] = {};
    values[index] = V();
    --qty;

    // rehash and reinsert any items in a cluster with the deleted item
    for (size_t i = (index+1) % capacity; key_list[i].has_value();
         i = (i+1) % capacity) {
      K rekey = *key_list[i];
      V revalue = values[i];
      --qty;

      put(rekey, revalue);
    }

    // if capacity is too large halve it
    if (qty > 0 && qty <= capacity/8)
      resize(capacity/2);
  }

  std::vector<K> keys() {
    std::vector<K> thekeys;
    for (size_t i = 0; i < capacity; ++i)
      if (key_list[i].has_value())
        thekeys.push_back(*key_list[i]);
    return thekeys;
  }
};


template <typename K, typename V>
struct Node {
  K key;
  V value;
  Node<K,V>* next;

  Node(K key, V value, Node<K,V>* next) {
    this->key = key;
    this->value = value;
    this->next = next;
  }
};


#endif
