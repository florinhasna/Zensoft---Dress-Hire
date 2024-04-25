#ifndef _HASH_HPP_
#define _HASH_HPP_

#include <optional>
#include <vector>
#include <memory>
#include <stdexcept>
#include <string>
#include <iostream>

// Template class for Linear Probing Hash Table
template <typename K, typename V>
class LinearProbingHash {
private:
    std::optional<K>* key_list;  // Array to store keys using optional for empty or removed slots
    std::unique_ptr<V>* values;  // Array to store values using smart pointers for automatic memory management
    size_t qty;                  // Current number of elements stored in the hash table
    size_t capacity;             // Maximum capacity of the hash table

public:
    // Constructor initializes hash table with a default size of 100
    LinearProbingHash() : key_list(new std::optional<K>[100]), values(new std::unique_ptr<V>[100]), qty(0), capacity(100) {}

    // Destructor cleans up allocated memory
    ~LinearProbingHash() {
        delete[] key_list;
        delete[] values;
    }

    // Adds a key-value pair to the hash table or updates the value if the key already exists
    void put(const K& key, V value) {
        size_t index = pos(key);
        if (!key_list[index].has_value()) {
            key_list[index] = key;  // Insert new key if the slot is empty
            values[index] = std::make_unique<V>(std::move(value));  // Uses smart pointer to manage the new value
            qty++;
        } else {
            values[index] = std::make_unique<V>(std::move(value));  
        }
        if (qty >= capacity / 2)  // Resize if load factor exceeds 0.5
            resize(capacity * 2);
    }

    // Retrieves a reference to the value associated with a key
    V& get(const K& key) {
        size_t index = pos(key);
        if (!values[index]) {  // Throw an exception if the key does not exist
            throw std::runtime_error("Attempted to access non-existing key.");
        }
        return *values[index];
    }

    void resize(size_t new_size) {
    std::optional<K>* new_keys = new std::optional<K>[new_size];
    std::unique_ptr<V>* new_values = new std::unique_ptr<V>[new_size];

    size_t old_capacity = capacity;
    // Temporarily set capacity to new_size to use in pos function
    capacity = new_size;

    for (size_t i = 0; i < old_capacity; ++i) {
        if (key_list[i].has_value()) {
            size_t new_index = std::hash<K>{}(*key_list[i]) % new_size; // Directly compute new index
            while (new_keys[new_index].has_value()) {  // Handle collision during rehash
                new_index = (new_index + 1) % new_size;
            }
            new_keys[new_index] = key_list[i];
            new_values[new_index] = std::move(values[i]);
        }
    }

    delete[] key_list;
    delete[] values;
    key_list = new_keys;
    values = new_values;
    // Reset capacity after all data is rehashed
    capacity = new_size;
    std::cout << "Resized: New capacity = " << capacity << ", Items = " << qty << std::endl;
}



    size_t pos(const K& key) {
    size_t index = std::hash<K>{}(key) % capacity;
    while (key_list[index].has_value() && key_list[index] != key) {
        index = (index + 1) % capacity;
        if (index == capacity) index = 0;  // Wrap around if the end of the array is reached
    }
    return index;
}


    // Returns a vector of all keys stored in the hash table
    std::vector<K> keys() {
        std::vector<K> thekeys;
        for (size_t i = 0; i < capacity; ++i) {
            if (key_list[i].has_value())
                thekeys.push_back(*key_list[i]);
        }
        return thekeys;
    }
};

#endif // _HASH_HPP_
