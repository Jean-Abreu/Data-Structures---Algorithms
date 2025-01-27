#include <iostream>
//Initializing a constant value
const int MAX_SIZE = 10;

int main(){
    //Initializing variables and array
    int arr[MAX_SIZE];
    int size, counter, frequency;
    //Taking user input for array size
    std::cout << "Enter size for array (Maximum of 10): ";
    std::cin >> size;
    //Error message in case user enters invalid value
    while(size > MAX_SIZE || size < 0){
        std::cout << "Invalid size. Try again (Max size of 10): ";
        std::cin >> size;
    }
    //User input for array variables
    std::cout << "Enter variables for array: " << std::endl;
    for(int i = 0; i < size; i++){
        std::cin >> arr[i];
    }
    //Printing out the array
    std::cout << "Array: ";
    for(int i = 0; i < size; i++){
        std::cout << arr[i];
        if(i < size - 1){
            std::cout << ", ";
        } else{
            std::cout << std::endl;
        }
    }
    //Taking input on which variable frequency will be searched for
    std::cout << "Which variable would you like to search the frequency for?" << std::endl;
    std::cin >> frequency;
    //For loop adding to counter depending on variable frequency
    for(int i = 0; i < size; i++){
        if(arr[i] == frequency){
            ++counter;
        }
    }
    //Outputting frequency
    std::cout << "Frequency: " << counter;

    return 0;
}

//Declare an array of size 10 and initialize it with 10 integers
//Ask user for an element
//Find how many times that element appears in the array and prints the frequency