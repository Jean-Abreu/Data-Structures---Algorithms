#include <iostream>

//Creating a node
struct Task{
    std::string task_description; //Data inside of the node includes description 
    int priority;                //and priority level. Next points to the next task.
    Task* next;
};

//Defining the linked list class
class LinkedList{
    //Pointer to the first node in the list
    Task* head;
public:
    //Constructor initializes head to NULL
    LinkedList() : head(NULL) {}

    //Function to Insert a new task at the beginning of the list
    void insertAtBeginning(std::string task, int value){
        Task* newTask = new Task();
        newTask->task_description = task;
        newTask->priority = value;
        head = newTask;
    }

    //Function to Insert a new task at the end of the list
    void insertAtEnd(std::string task, int value){
        Task* newTask = new Task();
        newTask->task_description = task;
        newTask->priority = value;
        newTask->next = NULL;

        //If the list is empty, update the head to the new node
        if(!head){
            head = newTask;
            return;
        }

        //Traverse to the last task
        Task* temp = head;
        while (temp->next){
            temp = temp->next;
        }

        //Update the last task's next to the new task
        temp->next = newTask;
    }

    //Function to Insert a new node at a specific position in the list
    void insertAtPosition(std::string task, int value, int position){
        if(position < 1){
            std::cout << "Position should be greater or equal to 1." << std::endl;
            return;
        }

        if(position == 1){
            insertAtBeginning(task,value);
            return;
        }

        Task* newTask = new Task();
        newTask->task_description = task;
        newTask->priority = value;

        //Traverse to the task before the desired position
        Task* temp = head;
        for(int i = 1; i < position - 1 && temp; ++i){
            temp = temp->next;
        }

        //If the position is out of range, print an error message
        if(!temp){
            std::cout << "Position out of range." << std::endl;
            delete newTask;
            return;
        }

        //Insert the new task at the desired position
        newTask->next = temp->next;
        temp->next = newTask;

    }

    //Function to Delete the first node of the list
    void deleteFromBeginning(){
        if (!head){
            std::cout << "List is empty." << std::endl;
            return;
        }

        Task* temp = head;
        head = head->next;
        delete temp;
    }

    //Function to Delete the last node of the list
    void deleteFromEnd(){
        if(!head){
            std::cout << "List is empty." << std::endl;
            return;
        }

        if(!head->next){
            delete head;
            head = NULL;
            return;
        }

        //Traverse to the second-to-last node
        Task* temp = head;
        while(temp->next->next){
            temp = temp->next;
        }

        //Delete the last node
        delete temp->next;
        //Set the second-to-last node's next to NULL
        temp->next = NULL;
    }

    //Function to Delete a task at a specific positon
    void deleteFromPosition(int position){
        if(position < 1){
            std::cout << "Position should be >= 1." << std::endl;
            return;
        }
        if(position == 1){
            deleteFromBeginning();
            return;
        }

        Task* temp = head;
        for(int i = 1; i < position - 1 && temp; ++i){
            temp = temp->next;
        }

        if(!temp || !temp->next){
            std::cout << "Position out of range." << std::endl;
            return;
        } 

        //Save the task to be deleted 
        Task* taskToDelete = temp->next;
        //Update the next pointer
        temp->next = temp->next->next;
        //Delete the node
        delete taskToDelete;
    }

    //Function to search for a task based off of description
    void search(std::string task){
        if(!head){
            std::cout << "List is empty." << std::endl;
            return;
        }
        Task* temp = head;
        while(temp){
            if(temp->task_description == task){
                std::cout <<"Task found with priority: " << temp->priority << std::endl;
                break;
            } else{
                temp = temp->next;
            }  
        }
    }

    //Function to print the task of the linked list
    void display(){
        if(!head){
            std::cout << "List is empty." << std::endl;
            return;
        }
        Task* temp = head;
        while(temp){
            std::cout << temp->task_description << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
};


int main(){
    //Initialize a new linked list
    LinkedList list1;
    std::string task;

    //Insert elements at the end
    list1.insertAtEnd("Do laundrey", 1);
    list1.insertAtEnd("Get milk", 2);

    std::cout << "Linked list after insertions: ";
    list1.display();

    std::cout << "Task: ";
    std::getline(std::cin, task);
    list1.search(task);

    //Need to make a switch case acting as the menu for user

    //List of functions within linked list:
    //insertAtBeginning(string, int), insertAtEnd(string, int), insertAtPosition(string, int, position)
    //deleteFromBeginning(), deleteFromEnd(), deleteFromPosition(int position), display(), search(string)

    return 0;
}


//TODO:
//Function is working. Need to thoroughly understand the properties of the function.
//Need to make a UI following the specifications of Task Manager assignment.
//Once these steps are followed, need to go through and make a recording with voiceover.
//Need to incorporate a way to search for a task based off it's description and list it's priority.
