#include <iostream>

//Defining a struct for the hash table entries
struct HashEntry{
    char key; //Each character from the string will act as the key
    int value; //Represents the frequency of each character
    bool isOccupied; //Flag to indicate whether the current index is full or not

    HashEntry() : key('\0'), value(0), isOccupied(false) {}
};

