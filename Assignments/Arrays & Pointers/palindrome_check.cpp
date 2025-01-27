#include <iostream>
//Initializing max size variable
const int MAX_SIZE = 10;
//Function to check if array are variables
bool isPalindrome(int arr[], int size) {
    //For loop comparing variables
    for (int i = 0; i < size / 2; i++) { //Loop ends halfway through array
        if (arr[i] != arr[size - i - 1]) { //Variables being compared are opposing indexes
            return false;  // If two variables are not alike, false is returned
        }
    }
    return true;  // If all pairs are alike, array is a palindrome
}

int main(){
    //Initializing array and variables
    int arr[MAX_SIZE];
    int size;
    //Taking user input
    std::cout << "Enter a size for the array (Maximum of 10): ";
    std::cin >> size;
    //Error handling
    while(size > MAX_SIZE || size < 0){
        std::cout << "Invalid size. Try again (Max of 10): ";
        std::cin >> size;
    }
    //Taking user input
    std::cout << "Enter values for array: " << std::endl;
    for(int i = 0; i < size; i++){
        std::cin >> arr[i];
    }

    //Using function and outputting result based of true or false
    if(isPalindrome(arr, size)){
        std::cout << "Array is a palindrome." << std::endl;
    } else {
        std::cout << "Array is not a palindrome.";
    }



    return 0;
}

//Declare an array of size 10 and initialize it with 10 integers
//Check if the array is a palindrome
//Print whether the array is palindrome or not

//Use a nested for loop to split the array and compare from back to end