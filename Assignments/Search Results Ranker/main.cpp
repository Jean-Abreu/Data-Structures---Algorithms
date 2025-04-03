#include <iostream>
#include <vector>

//Function to partition the array
int partition(std::vector<int>& arr, int low, int high){
    int pivot = arr[high]; // pivot point
    int i = low - 1; //Index of smaller element

    for(int j = low; j < high; j++){
        if(arr[j] > pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return(i + 1);
}

//Quick sort function
void quickSort(std::vector<int>& arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high); //Partitioning index

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