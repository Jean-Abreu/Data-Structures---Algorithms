/* Question 4: (Any one of the 5 real time applications for each group as assigned in
    class) Screen recording with voice over is required for this question
    Queue real time Application questions:
    Problem 1: Print Job Scheduling (Jean, Edward, Rechy, Langley)
    Problem Statement:
    A printer processes print jobs in FIFO order. Implement a queue-based print
    scheduler where:
    • Users can add a print job (enqueue).
    • The printer processes jobs in order (dequeue).
    • The system should display the current queue of print jobs.
    Output:
    Added to Print Queue: Report.pdf
    Added to Print Queue: Presentation.pptx
    Current Print Queue: Report.pdf | Presentation.pptx |
    Printing: Report.pdf
    Current Print Queue: Presentation.pptx | */


#include <iostream>
#include <string>

// Node structure representing a single print job
struct PrintJob {
    std::string fileName; //Data
    PrintJob* next; //Next
    
    PrintJob(std::string name) { //Constructor for PrintJob node
        this->fileName = name; //Data pointer
        this->next = nullptr; //Next pointer
    }
};

// Class to implement print job scheduling using a queue
class PrintQueue {
private:
    PrintJob* front;  // Front of the queue
    PrintJob* rear;   // Rear of the queue

public:
    // Constructor
    PrintQueue() { front = rear = nullptr; }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to add a print job to the queue
    void enqueue(std::string fileName) {
        PrintJob* newJob = new PrintJob(fileName);
        
        if (isEmpty()) {
            front = rear = newJob;
        } else {
            rear->next = newJob;
            rear = newJob;
        }
        
        std::cout << "Added to Print Queue: " << fileName << std::endl;
    }

    // Function to process a print job (dequeue)
    void dequeue() {
        if (isEmpty()) {
            std::cout << "No jobs to print!" << std::endl;
            return;
        }

        PrintJob* temp = front;
        std::cout << "Printing: " << temp->fileName << std::endl;
        front = front->next;

        // If queue becomes empty, reset rear pointer
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp; // Free memory of printed job
    }

    // Function to display the current print queue
    void display() {
        if (isEmpty()) {
            std::cout << "Current Print Queue: Empty" << std::endl;
            return;
        }

        std::cout << "Current Print Queue: ";
        PrintJob* temp = front;
        while (temp != nullptr) {
            std::cout << temp->fileName << " | ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

// Main function to test the Print Job Scheduler
int main() {
    PrintQueue printer;

    // Adding print jobs
    printer.enqueue("Report.pdf");
    printer.enqueue("Presentation.pptx");

    // Display current queue
    printer.display();

    // Process (print) jobs
    printer.dequeue();
    printer.display();

    printer.dequeue();
    printer.display();

    return 0;
}
