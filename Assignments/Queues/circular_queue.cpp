/* Question 3: Circular Queue Implementation
Modify your array-based queue from Question 1 to implement a circular queue. Ensure
that:
1. Enqueue and dequeue operations work efficiently using modulus (%) operator.
2. The queue can wrap around and reuse empty slots.
3. Handle queue full and queue empty conditions properly.
Test Case:
• Enqueue 5 elements.
• Dequeue 2 elements.
• Enqueue 2 more elements and display the final queue. */

#include <iostream>

const int MAX = 5;

class queue{

    private:
        int *arr;
        int front, size;
        int capacity;

    public:
        //Constructor for queue, initializing the front and rear to be -1 to indicate empty queue
        queue(){
            arr = new int[MAX];
            capacity = MAX;
            front = 0;
            size = 0;
        }

        void enqueue(int value){
            //Function to add element to the rear of the queue
            //Steps to implement:
            //1)Check if the queue is full, if so return an overflow error and exit
            //2)If the queue is not full, increment the rear pointer to the next available position
            //3)Insert element at the rear

            if(size == MAX){ //Checking if the rear value is maximum position
                std::cout << "Queue Overflow! Cannot insert more elements." << std::endl;
                return;
            } 
            
            int rear = (front + size - 1) % capacity;


            arr[rear] = value; //Adding the value to the queue from the rear
            size++;
            std::cout << "Inserted: " << value << std::endl; //Printing out the performed function
        }

        int dequeue(){
            //Function to remove element from the rear of the queue
            //Steps to implement:
            //1)Check if the queue is empty, if so return and underflow error
            //2)Remove the element at the front
            //3)Increment the front pointer to the next element
            
            //If queue is empty
            if(size == 0){
                return -1;
            }
            int res = arr[front];
            front = (front + 1) % capacity;
            size--;
            return res;
            
        }

        void peek(){
            //Function to display the top element of the queue
            if(front == 0){
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

            if(size = capacity){ //Conditional to see if full 
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
            for(int i = 0; i <= size; i++){
                std::cout << arr[i] << " ";
            } std::cout << std::endl;
        }
};

int main(){
    
    queue q;

    q.enqueue(10);
    
    q.enqueue(20);
    
    q.enqueue(30);
    
    q.enqueue(40);
    
    q.dequeue();
    
    q.dequeue();
    
    q.enqueue(50);

    return 0;
}
