//Implementing a queue using an array. The goal is to include:

/* 1. enqueue(int value): Insert an element at the rear.
2. dequeue(): Remove an element from the front.
3. peek(): Display the front element without removing it.
4. isFull(): Check if the queue is full.
5. isEmpty(): Check if the queue is empty.
6. display(): Print all elements of the queue. */

//Requirements:
/* -Define the maximum queue size as MAX = 5
-Handle queue overflow and underflow conditions
-Test the program with at least 5 enqueue operations, followed by 2 dequeue
operations, and print the remaining elements */

#include <iostream>

const int MAX = 5;

class queue{

    private:
        int arr[MAX];
        int front, rear;

    public:
        //Constructor for queue, initializing the front and rear to be -1 to indicate empty queue
        queue(){
            front = -1;
            rear = -1;
        }

        void enqueue(int value){
            //Function to add element to the rear of the queue
            //Steps to implement:
            //1)Check if the queue is full, if so return an overflow error and exit
            //2)If the queue is not full, increment the rear pointer to the next available position
            //3)Insert element at the rear

            if(rear == MAX -1){ //Checking if the rear value is maximum position
                std::cout << "Queue Overflow! Cannot insert more elements." << std::endl;
                return;
            } 

            if(front == -1){ //Determining if this will be the first value of the queue
                front = 0;
            }

            arr[++rear] = value; //Adding the value to the queue from the rear
            std::cout << "Inserted: " << value << std::endl; //Printing out the performed function
        }

        void dequeue(){
            //Function to remove element from the rear of the queue
            //Steps to implement:
            //1)Check if the queue is empty, if so return and underflow error
            //2)Remove the element at the front
            //3)Increment the front pointer to the next element
            if(front == -1 || front > rear){
                std::cout << "Queue Underflow! No elements to delete. " << std::endl;
                front = rear = -1; //Reset queue
                return;
            }
            std::cout << "Deleted: " << arr[front] << std::endl;
            front++;
            if(front > rear) //Reset when empty
                front = rear = -1;
            
        }

        void peek(){
            //Function to display the top element of the queue
            if(front == -1){
                std::cout << "Queue is Empty!" << std::endl;
                return;
            } else {
                std::cout << "Front Element: " << arr[front] << std::endl;
            }
        }

        bool isFull(){
            //Checking to see if the queue is full
            if(front == -1){ //Conditional to see if empty
                return false;
            }

            if(rear = MAX - 1){ //Conditional to see if full 
                return true;
            }
        }

        bool isEmpty(){
            //Checking to see if the queue is empty
            if(front == -1){
                return true;
            } else {
                return false;
            }
        }

        void display(){
            //Displaying the entirety of the queue
            if(front == -1){
                std::cout << "Queue is empty!" << std::endl;
                return;
            }
            std::cout << "Queue Elements: ";
            for(int i = 0; i <= rear; i++){
                std::cout << arr[i] << " ";
            } std::cout << std::endl;
        }
};

int main(){
    
    queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();

    if(q.isEmpty()){
        std::cout << "Queue is empty!" << std::endl;
    } else {
        std::cout << "Queue is not empty!" << std::endl;
    }

    if(q.isFull()){
        std::cout << "Queue is full!" << std::endl;
    } else {
        std::cout << "Queue is not full!" << std::endl;
    }

    return 0;
}
