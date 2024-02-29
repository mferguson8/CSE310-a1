#include <iostream>
#include <string>
#include <cmath>
#include "hash.h"

using namespace std;

int hash_function(string text, int tableSize)
{
    // Implement your own hash function here
    int hashValue = 0;

    for (char ch : text)
    {
        hashValue += ch;
    }
    return hashValue % tableSize;
}
#include <list>
// Node structure for linked list
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
    HashTable(int tableSize) : size(tableSize)
    {
        table = new std::list<Node *>[size];
    }

    ~HashTable()
    {
        delete[] table;
    }

    // Function to insert a key into the hash table
    void insert(const std::string &key)
    {
        int hashed = hash_function(key, 9);
        Node *newNode = new Node(key);
        table[hashed].push_back(newNode);
    }
    // Function to calculate the standard deviation of the hash table
    float calculateMean()
    {
        int totalLength = 0;
        int nonEmptySlots = 0;

        for (int i = 0; i < size; ++i)
        {
            if (!table[i].empty())
            {
                totalLength += table[i].size();
                nonEmptySlots++;
            }
        }

        if (nonEmptySlots == 0)
        {
            return 0; // To avoid division by zero
        }

        return static_cast<float>(totalLength) / nonEmptySlots;
    }

    // Function to calculate the standard deviation of the slot lengths
    float calculateStandardDeviation()
    {
        float mean = calculateMean();
        float variance = 0;

        for (int i = 0; i < size; ++i)
        {
            if (!table[i].empty())
            {
                int length = table[i].size();
                variance += pow(length - mean, 2);
            }
        }

        variance /= size; // dividing by total number of slots
        float standardDeviation = sqrt(variance);
        return standardDeviation;
    }
    // Function to get the lengths of all slots in the hash table
    int getSlotLength(int slot)
    {
        return table[slot].size();
    }

    // Function to get the contents of a specific slot in the hash table
    std::list<std::string> getSlotContents(int slot)
    {
        std::list<std::string> slotContents;
        for (Node *curr : table[slot])
        {
            slotContents.push_back(curr->key);
        }
        return slotContents;
    }
};
