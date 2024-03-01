#ifndef HASH_H
#define HASH_H

#include <string>
#include <list>

int hash_function(std::string text, int tableSize);

struct Node
{
    std::string key;
    Node *next;

    Node(const std::string &k) : key(k), next(nullptr) {}
};

class HashTable
{
private:
    int size;
    std::list<Node *> *table;

public:
    HashTable(int tableSize);
    ~HashTable();

    void insert(const std::string &key);
    double calculateStandardDeviation();

    int getSlotLengths(int slotIndex);
    std::list<std::string> getSlotContents(int slot);
    void printSlotContents(int slot);
    float calculateMean();
};

#endif
