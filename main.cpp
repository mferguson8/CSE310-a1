/*
CSE 310 Hash Function DIY Contest
Instructor: Yiran "Lawrence" Luo
Your name(s): Michael Ferguson
Your team alias: None
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "hash.h"
using namespace std;

int main()
{

    int k = 0;
    int n = 0;
    string texts[500];

    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line))
    {
        texts[n] = line;
        n++;
    }
    // WARNING: End of the tokenizer, DO NOT change this part!

    // By this point, k is the # of slots, and n is the # of tokens to fit in
    // texts[] stores the input sequence of tokens/keys to be inserted into your hash table

    // The template is able to be compiled by running
    //   make
    //   ./encoder < inputs/sample_input.txt
    // which puts out the placeholders only.

    // Your time to shine starts now
    // Create a hash table

    HashTable hashTable(k);

    // Insert tokens/keys into the hash table
    for (int i = 0; i < n; i++)
    {
        hashTable.insert(texts[i]);
    }

    // Print the contents of the first 5 slots
    cout << "==== Printing the contents of the first 5 slots ====" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Slot " << i << ": " << hashTable.getSlotContents(i) << endl;
    }

    // Print the slot lengths
    cout << "==== Printing the slot lengths ====" << endl;
    for (int i = 0; i < k; i++)
    {
        cout << "Slot " << i << " length: " << hashTable.getSlotLengths(i) << endl;
    }

    // Print the standard variance
    cout << "==== Printing the standard variance ====" << endl;
    cout << hashTable.calculateStandardDeviation() << endl;

    return 0;
}