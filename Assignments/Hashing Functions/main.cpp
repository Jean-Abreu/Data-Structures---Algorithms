#include <iostream>

//Defining a struct for the hash table entries
struct HashEntry{
    char key; //Each character from the string will act as the key
    int value; //Represents the frequency of each character
    bool isOccupied; //Flag to indicate whether the current index is full or not

    HashEntry() : key('\0'), value(0), isOccupied(false) {}
};

//Creating a hash table class that incorporates linear probing
class HashTable {
    private:
        static const int SIZE = 128; //Enough for the ASCII characters
        //A hash table array that is based off the constant size we created
        HashEntry table[SIZE]; 
        //The hash function
        int hash(char key){ 
            return key % SIZE; //The ASCII value of the character is used for this function
        }
    public:
        //Insert function 
        void insert(char key){
            int index = hash(key); //Use the hashing function to assign an index
            int originalIndex = index; //Saving the original index to prevent infinite looping
            //While loop to see if linear probing is necessary
            while(table[index].isOccupied && table[index].key != key){
                index = (index + 1) % SIZE;
                //If we continuously probe and land on the same index, the table is full
                if(index == originalIndex) return;
            }
            //If/else to update indices
            if(!table[index].isOccupied){
                table[index].key = key;
                table[index].value = 1;
                table[index].isOccupied = true;
            } else {
                //If index is occupied and has the same key, then we increase the frequency
                table[index].value++;
            }
        }
        //Frequency function
        int getFrequency(char key){
            int index = hash(key); //Using the hash function to assign an index
            int originalIndex = index; //Saving the index to prevent infinite looping
            while(table[index].isOccupied){
                if(table[index].key == key)
                    return table[index].value;
                index = (index + 1) % SIZE;
                if(index == originalIndex)break;
            }
            return 0;
        }
};
