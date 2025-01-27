#include <iostream>
//Initializing a constant int
const int MAX_SIZE = 10;

int main(){
    //Initializing variables and array
    int size, max, min;
    int arr[MAX_SIZE];
    //Taking input for size of the array
    std::cout << "Enter size for array (Maximum of 10): ";
    std::cin >> size;
    //Produces an error and continues prompting user for size of array
    //If the input is too high or low
    while(size > MAX_SIZE || size < 0){
        std::cout << "Enter a valid size for the array (Max of 10): ";
        std::cin >> size;
    }
    //Taking user input for the array
    std::cout << "Enter values for array: " << std::endl;
    for(int i = 0; i < size; i++){
        std::cin >> arr[i];
    }
    //Printing the array
    std::cout << "Array: ";
    for(int i = 0; i < size; i++){
        std::cout << arr[i];
        if(i < size - 1){
            std::cout << ", ";
        } else{
            std::cout << std::endl;
        }
    }
    //Looping through the array to determine min and max values
    for(int i = 0; i < size; i++){
        max = arr[0];
        if(arr[i] > max){
            max = arr[i];
        }
        min = arr[0];
        if(arr[i] < min){
            min = arr[i];
        }
    }
    //Outputting maximum & minimum values
    std::cout << max << std::endl;
    std::cout << min;

    return 0;
}

//Declare an array of size 10 and initialize it with 10 random integers
//Find and print the maximum and minimum values in the array