#include <iostream>

int main(){
    //Initializing array of size 5 with elements
    int arr[5] = {1, 2, 3, 4, 5};
    //Initializing a pointer and dereferencing the address of the array
    int *ptr = arr;
    //Outputting the array using the pointer
    std::cout << "Current Array: ";
    for(int i = 0; i < 5; i++){
        //Since ptr is point to the address of the array, we can traverse by adding
        std::cout << *(ptr + i) << " ";
    }
    //Creating a new line 
    std::cout << std::endl;
    //Adjusting the third element of the array using pointer arithmetic
    *(ptr + 2) = 7;
    //Outputting the updated array
    std::cout << "Updated Array: ";
    for(int i = 0; i < 5; i++){
        std::cout << *(ptr + i) << " ";
    }

    return 0;
}

//Declare an array of 5 integers
//Use a pointer to access and print the elements of the array using pointer arithmetic
//Modify one of the elements in the array using the pointer and print the updated array