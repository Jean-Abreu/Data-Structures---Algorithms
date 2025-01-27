#include <iostream>

int main(){
    //Initializing array
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //Printing out the array
    std::cout << "Current array: ";
    for(int i = 0; i < 10; i++){
        std::cout << arr[i];
        if(i < 9){
            std::cout << ", ";
        } else{
            std::cout << std::endl;
        }
    }
    //Reversing the array
    //Outer for loop selects a variable
    for(int i = 0; i < 10; i++){
        //Inner for loop switches positions of first and last index
        for(int j = i + 1; j < 10; j++){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //Outputting reversed array
    std::cout << "Reversed array: ";
    for(int i = 0; i < 10; i++){
        std::cout << arr[i];
        if(i < 9){
            std::cout << ", ";
        } else{
            std::cout << std::endl;
        }
    }

    return 0;
}

//Declare an array of size 10 and initiliaze with 10 integers.
//Reverse the elements of the array without using and extra array
//Print the array after reversal