#include <iostream>
#include <algorithm>

//Initializing a variable with a maximum value of 50
    const int n = 50;

int main(){
    //Initializing size
    int size;
    int i;
    
    //Creating an array 
    int arr[n];
    //Creating a backup array
    int backup[n];

    //Taking input for array size
    std::cout << "Array size (1 to  50): ";
    std::cin >> size;

    //Keeping user input from 1 - 50
    while(size < 1 || size > n){
        std::cout << "Invalid size, please enter a value between 1 & 100: ";
        std::cin >> size;
    } //This loop will continue until user enters satisfiable value

    //Taking input for array elements
    for(i = 0; i < size; i++){
        std::cout << "Enter numbers for array: ";
        std::cin >> arr[i];
        backup[i] = arr[i]; //Saving the original state
    }

    //Printing out the array
    std::cout << "Array: ";
    //Iterating through the array
    for(i = 0;i < size; i++){
        std::cout << arr[i];
        //Printing ',' after every element except the last one
        if(i < size - 1){
            std::cout << ", ";
        }
    }
    //Creating an indentation between statements
    std::cout << std::endl;

    //Sort the array using std::sort(start_pointer, end_pointer)
    std::sort(arr, arr + size);
    //Printing the largest and smallest elements.
    std::cout << "Largest integer: " << arr[size - 1] << std::endl;
    std::cout << "Smallest integer: " << arr[0] << std::endl;

    //Restoring the array to original state
    for(i = 0; i < size; i++){
        arr[i] = backup[i];
    } //Necessary due to sorting the array

    //Reversing the restored array
    std::reverse(arr, arr + size);
    std::cout << "Reversed array: ";
    for(i = 0; i < size; i++){
        std::cout << arr[i];
        if(i < size - 1){
            std::cout << ", ";
        }
    }

    std::cout << std::endl;

    //Searching for an element in the array 
    int user_key; //Initializing variable for user input
    int pos; //Initializing variable for index value
    //Taking input
    std::cout << "Which number would you like to search for? ";
    std::cin >> user_key;
    //For loop to determine which key matches input
    for(int i = 0; i < size; i++){
        if(arr[i] == user_key){
            pos = i;
            break;
        }
    }
    //Printing out desired element and index
    std::cout << "Element: " << user_key << std::endl;
    std::cout << "Index: " << pos;
    
    

    return 0;
}

/*Write a C++ program that performs the following operations on a
one-dimensional array of integers:
1.Input the size of the array (maximum size is 50).
2.Input the elements of the array.
3.Print the elements of the array.
4.Find and print the largest and smallest elements in the array.
5.Reverse the array and display the reversed array.
6.Search for an element in the array and print its index (if found).
*/