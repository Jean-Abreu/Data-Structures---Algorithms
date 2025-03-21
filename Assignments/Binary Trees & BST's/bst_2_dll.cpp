/* Question 3: (Each group solves one as specified) (10 points)
Problem on Binary Search Tree Questions (BST): (Short answers)
1. Convert BST to a Sorted Doubly Linked List (Jean, Edward, Rechy, Langley) */

#include <iostream>

//Node structure for binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

//Reversive function to convert BST to DLL
void bst_2_dll(Node* root, Node** head)
{
    //Base case
    if(root == NULL)
    {
        return;
    }

    //Initialize previously visited node as NULL. This
    //is static to make sure the same value is accessible in all 
    //recursive calls
    static Node* prev = NULL;

    //Recursively convert left subtree
    bst_2_dll(root->left, head);

    //Now convert this node
    if(prev == NULL)
    {
        *head = root;
    }
    else 
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    
    //Finally convert right subtree
    bst_2_dll(root->right, head);
}

//Allocates a new node with given data 
Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}

//Function to print nodes in a given doubly linked list
void printList(Node* Node)
{
    while (Node != NULL)
    {
        std::cout << Node->data << " ";
        Node = Node->right;
    }
}

int main(){
    //Creating the tree
    Node* root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->right->left = newNode(30);

    //Converting tree to DLL
    Node* head = NULL;
    bst_2_dll(root, &head);
    
    //Printing the converted list
    printList(head);


    return 0;
}