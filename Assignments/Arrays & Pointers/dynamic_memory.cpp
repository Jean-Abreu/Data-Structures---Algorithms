#include <iostream>

int main(){
    int *pNum = new int; //Allocating space for pNum of size integer
    *pNum = 10; //Assigning number 10 to pNum

    std::cout << *pNum; //Printing out the data stored in pNum

    delete pNum; //Deallocating the memory for pNum
    

    return 0;
}

//Write a C++ program that uses new to dynamically allocate memory
//For a single integer, assigns a value to it, and prints it.
//After that, free the dynamically allocated memory using delete.