#include <iostream>
#include <string>
#include <cmath>
#include "hash.h"
#include <list>

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

HashTable::HashTable(int tableSize)
{
    table = new list<Node *>[tableSize];
    size = tableSize;
}

HashTable::~HashTable()
{
    delete[] table;
}

void HashTable::insert(const std::string &key)
{
    int hashed = hash_function(key, size);
    Node *newNode = new Node(key);
    table[hashed].push_back(newNode);
}

float HashTable::calculateMean()
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
double HashTable::calculateStandardDeviation()
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
int HashTable::getSlotLengths(int slotIndex)
{
    return table[slotIndex].size();
}
list<string> HashTable::getSlotContents(int slot)
{
    list<string> slotContents;
    for (Node *curr : table[slot])
    {
        slotContents.push_back(curr->key);
    }
    return slotContents;
}
void HashTable::printSlotContents(int slot)
{
    for (Node *curr : table[slot])
    {
        cout << curr->key << " ";
    }
    cout << endl;
}