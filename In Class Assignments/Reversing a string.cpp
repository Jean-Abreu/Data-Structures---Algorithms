#include <iostream>

//Function for reversing the string
std::string reverseString(const std::string &str){
    if (str.empty()) //This is step one: Checking if string is empty
        return ""; //Returning an empty string
    return reverseString(str.substr(1)) + str[0]; //Moves one character to the end and processes rest of string
}

int main(){
    //Initializing variables
    std::string input;
    std::string reversed;
    //Taking user input
    std::cout << "Enter a string: ";
    std::cin >> input;
    //Outputting user string and the reversed string
    std::cout << "Original string: " << input << std::endl;
    reversed = reverseString(input);
    std::cout << "Reversed string: " << reversed << std::endl;

    return 0;
}