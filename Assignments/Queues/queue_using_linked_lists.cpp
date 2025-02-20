/* Question 2: Implement a Queue Using a Linked List
Write a C++ program to implement a queue using a linked list. Your program should
include the following functions:
1. enqueue(int value): Insert an element at the rear.
2. dequeue(): Remove an element from the front.
3. peek(): Display the front element without removing it.
4. isEmpty(): Check if the queue is empty.
5. display(): Print all elements of the queue.
Requirements:
• Use a dynamically allocated linked list.
• Handle queue underflow when trying to dequeue from an empty queue.
• Test the program with at least 5 enqueue operations, followed by 3 dequeue
operations, and print the remaining elements. */

#include<iostream>
const int MAX = 5;

//Node struct representing a single node in the linked list
struct node{
    int data;
    node* next;
    node(int new_data)
    {
        this->data = new_data;
        this->next = nullptr;
    }
};

//Class to implement queue operations using a linked list
class queue{
    private:
        //Pointer to the front and the rear of the linked list
        node *front, *rear;

    public:
        //Constructor to initialize the front and rear
        Queue() { front = rear = nullptr; }

        //Function to see if the queue is empty
        bool isEmpty(){
            //If the front and rear are null, then the queue is
            //empty, otherwise its not
            if(front == nullptr){
                return true;
            }
            return false;
        }

        //Function to add an element to the queue
        void enqueue(int new_data){
            //Create a new linked list node
            node* new_node = new node(new_data);

            //If queue is empty, the new node is both the front
            //and rear
            if(this->isEmpty()){
                front = rear = new_node;
                return;
            }

            //Add the new node at the end of the queue and
            //change rear
            rear->next = new_node;
            rear = new_node;
        }

        //Function to remove an element from the queue
        void dequeue(){
            //If queue is empty, return
            if(this->isEmpty()){
                std::cout << "Queue Underflow" << std::endl;
                return;
            }
            //Store previous front and move front on node
            //ahead
            node* temp = front;
            front = front->next;
            //If front becomes nullptr, then change rear also
            //to nullptr
            if(front == nullptr)
                rear = nullptr;
            
            //Deallocate memory of the old front node
            //delete temp;
        }
        //Function to get the front element of the queue
        int peek(){
            //Checking if the queue is empty
            if(this->isEmpty()){
                std::cout << "Queue is empty" << std::endl;
                return -1;
            }
            return front->data;
        }
        //Function to display the entirety of the linked list
        void display() {
            //Checking if the queue is empty
            if(this->isEmpty()){
                std::cout << "Queue is empty" << std::endl;
                return;
            }
            node* temp = front;
            while(temp->next != nullptr){
                std::cout << temp->data;
            }
        }

};

int main()
{

    queue q;
     // Enqueue elements into the queue
     q.enqueue(10);
     q.enqueue(20);
 
     // Display the front and rear elements of the queue
     std::cout << "Queue Front: " << q.peek() << std::endl;
 
     // Dequeue elements from the queue
     q.dequeue();
     q.dequeue();
 
     // Enqueue more elements into the queue
     q.enqueue(30);
     q.enqueue(40);
     q.enqueue(50);
 
     // Dequeue an element from the queue
     q.dequeue();
 
     // Display the front and rear elements of the queue
     std::cout << "Queue Front: " << q.peek() << std::endl;
     
    

    return 0;
}