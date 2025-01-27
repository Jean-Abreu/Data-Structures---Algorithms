#include <iostream>

int main(){
    //Initializing integer variable
    int x = 10;
    //Initializing integer pointer
    int *ptr_x;
    //Assigning pointer to variable
    ptr_x = &x;
    //Printing value of pointer
    std::cout << "Pointer value: "<< *ptr_x << std::endl;
    //Changing the value of the variable using pointer
    *ptr_x = 12;
    //Printing out changed value
    std::cout << "New pointer value: " << *ptr_x << std::endl;
    //Printing memory address of the integer variable
    std::cout << "Pointer address: " << ptr_x << std::endl;

    return 0;
}