#include <iostream>

//Function to maintain the Min-Heap property
template <typename T>
void heapify(T arr[], int n, int i) {
    int smallest = i;   //Assuming root is the smallest
    int left = 2 * i + 1;   //Left child index
    int right = 2 * i + 2;  //Right child index

    //Checking if the left child exists and is smaller than the root
    if(left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    //Checking if the right child exists and is smaller than the current smallest
    if(right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    //If the smallest is not the root, swap and continue heapifying
    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest); //Recursively heapify the affected subtree
    }
}

//Function to build a Min-heap from an unsorted array
template <typename T>
void buildMinHeap(T arr[], int n) {
    //Starting from the last non-leaf node and heapify each node up to the root
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
}

//Heap sort function
template <typename T>
void heapSort(T arr[], int n) {
    //Step 1: Build Min-Heap
    buildMinHeap(arr, n);
    //Step 2: Extract elements one by one
    for(int i = n -1; i > 0; i--){
        //Move the smallest element (root) to the end
        swap(arr[0], arr[i]);
        //Restore the Min-Heap property on the reduced heap
        heapify(arr, i, 0);
    }
}

//Function to print the array
template <typename T>
void printArray(T arr[], int n) {
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

//Main function
template <typename T>
void runHeapSort(T arr[], int n) {
    std::cout << "Unsorted array: ";
    printArray(arr, n);

    heapSort(arr, n);

    std::cout << "Sorted array (Descending order): ";
    printArray(arr, n);
}

int main(){
    int arr[] = {45, 12, 89, 34, 6, 73, 22, 90, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    runHeapSort(arr, n);
    return 0;
}