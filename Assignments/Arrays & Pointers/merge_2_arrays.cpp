#include <iostream>
#include <vector>


const int MAX_SIZE = 5;

void mergeArrays(int arr_1[], int arr_2[], std::vector<int>& arr_3, int n, int l){
    //Inserting elements from the first array
    arr_3.insert(arr_3.end(), arr_1, arr_1 + n);
    //Inserting elements from the second array
    arr_3.insert(arr_3.end(), arr_2, arr_2 + n);
    //Outputting the third array
    std::cout << "Third Array: ";
    for(int i = 0; i < n + l; i++){
        std::cout << arr_3[i];
        if(i < n + l - 1 ){
            std::cout << ", ";
        } else {
            std::cout << std::endl;
        }
    }
};

int main(){
    //Initializing arrays and size
    int arr_1[MAX_SIZE], arr_2[MAX_SIZE], size;
    //To allow the third array to be dynamic, it is made a vector
    std::vector<int> arr_3;
    
    //Taking user input for first array
    std::cout << "Enter size of first array (Maximum of 5): ";
    std::cin >> size;
    //Error handling
    while(size > MAX_SIZE || size < 0){
        std::cout << "Invalid size. Try again (Max of 10): ";
        std::cin >> size;
    }
    //Taking user input for array_1
    std::cout << "Enter variables for first array: ";
    for(int i = 0; i < size; i++){
        std::cin >> arr_1[i];
    }
    //Taking user input for array_2
    std::cout << "Enter size of second array (Maximum of 5): ";
    std::cin >> size;
    //Error handling
    while(size > MAX_SIZE || size < 0){
        std::cout << "Invalid size. Try again (Max of 10): ";
        std::cin >> size;
    }
    //Taking user input for array
    std::cout << "Enter variables for second array: ";
    for(int i = 0; i < size; i++){
        std::cin >> arr_2[i];
    }
    //Outputting array_1
    std::cout << "First Array: ";
    for(int i = 0; i < size; i++){
        std::cout << arr_1[i];
        if(i < size - 1){
            std::cout << ", ";
        } else {
            std::cout << std::endl;
        }
    }
    //Outputting array_2
    std::cout << "Second Array: ";
    for(int i = 0; i < size; i++){
        std::cout << arr_2[i];
        if(i < size - 1){
            std::cout << ", ";
        } else {
            std::cout << std::endl;
        }
    }
    //Initializing variables and assigning size
    int n = size;
    int l = size;
    //Calling upon function to merge arrays
    mergeArrays(arr_1, arr_2, arr_3, n, l);

    return 0;
}

//Declare two arrays, each of size 5
//Initialize both arrays with 5 integers each
//Merge the two arrays into a third array, ensuring that the elements of the second array are appended to the first array
//Print the merged array