#include <iostream>

int main(){
    //Initializing and allocating memory for array of 10 elements
    int* arr = new int[10];
    //Taking user input for array
    std::cout << "Enter values for array: ";
    for(int i = 0; i < 10; i++){
        std::cin >> arr[i];
    }
    //Initializing a pointer and dereferencing the address of arr
    int* ptr = arr;
    //Printing out the array using pointer
    std::cout << "Array: ";
    for(int i = 0; i < 10; i++){
        std::cout << *(ptr + i) << " ";//Using pointer arithmetic to traverse the array
    }
    //Deallocating the memory to prevent memory leak
    delete[] arr;

    return 0;
}

//Dynamically allocate an array of 10 integers using new[]
//Ask user to input value for the array
//Print the value of the array using a pointer
//Free the dynamically allocated memory using delete[]