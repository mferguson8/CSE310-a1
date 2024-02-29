#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int hash_function(string text, int tableSize) {
    // Implement your own hash function here
    int hashValue = 0;

    for(char ch : text) {
        hashValue += ch;
    }
    return hashValue % tableSize;
}
// Node structure for linked list
struct Node {
    std::string key;
    Node* next;
    
    Node(const std::string& k) : key(k), next(nullptr) {}
};


class HashTable {
private:
    int size;
    std::list<Node*>* table;

public:
    HashTable(int tableSize) : size(tableSize) {
        table = new std::list<Node*>[size];
    }

    ~HashTable() {
        delete[] table;
    }

    // Function to insert a key into the hash table
    void insert(int hash, const std::string& key) {
        Node* newNode = new Node(key);
        table[hash].push_back(newNode);
    }
}