#include <iostream>

int main(){
    //Initializing variable
    int num = 10;
    //Initializing pointers
    int *ptr_1 = &num;//Pointing to address of num
    int *ptr_2 = ptr_1;//Pointing to address of first pointer

    std::cout << "Initial value of first pointer: " << *ptr_1 << std::endl;//Printing out initial values
    std::cout << "Initial value of second pointer: " << *ptr_2 << std::endl;

    *ptr_2 = 11; //Modifying the data using the second pointer

    std::cout << "Modified value of first pointer: " << *ptr_1 << std::endl;//Printing out the modified values
    std::cout << "Modified value of second pointer: " << *ptr_2 << std::endl;

    

    return 0;
}

//Write a program that demonstrates the use of pointer to a pointer. 
//Declare an integer variable
//Create a pointer to the integer
//Create a pointer ot the pointer and use it to modify the value of the integer
//Print the value of the integer using both pointers