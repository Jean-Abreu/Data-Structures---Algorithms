#include <iostream>
#include <vector>

//Function to partition the array
int partition(std::vector<int>& arr, int low, int high){
    int pivot = arr[high]; //Selecting a pivot point
    int i = low - 1; //Starting point for sorting boundary

    for(int j = low; j < high; j++){ //Iterarting (and searching) through array
        if(arr[j] > pivot) {
            i++; //If conditions are met, boundary is incremented
            std::swap(arr[i], arr[j]); //And pivot point is swapped with element
        }
    }

    std::swap(arr[i + 1], arr[high]); //If condition is not met, pivot point is put at the front of the boundary
    return(i + 1);
}

//Quick sort function
void quickSort(std::vector<int>& arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high); //Calling the partition function to use in quick sort functionality

        quickSort(arr, low, pi - 1); //Sort left
        quickSort(arr, pi + 1, high); //Sort right
    }
}

int main() {
    std::vector<int> relevanceScores = {75, 85, 60, 95};

    int scoresSize = relevanceScores.size();

    std::cout << "Original Relevance Scores:\n";
    for(int i = 0; i < scoresSize; i++){
        std::cout << relevanceScores[i] << " ";
    }
    std::cout << "\n";

    quickSort(relevanceScores, 0, relevanceScores.size() - 1);

    std::cout << "Sorted Relevance Scores (Descending):\n";
    for(int i = 0; i < scoresSize; i++){
        std::cout << relevanceScores[i] << " ";
    }
    std::cout << "\n";
}