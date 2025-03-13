/* Question 1: (20 points)
Write a C++ program that implements a Binary Search Tree (BST) with functionalities to
insert, search, and delete elements. The program initializes a BST with 11 elements and
provides user-interactive options to perform operations on the tree.
Features of the program:
1. Insertion: Adds elements into the BST.
2. Search: Checks if an element is present in the BST.
3. Deletion: Removes a specific element while maintaining BST properties.
4. Inorder Traversal: Displays the tree elements in sorted order.  */


#include <iostream>

//Node structure for a Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

//Function to create a new Node
Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

//Function to insert a node in the BST
Node* insertNode(Node* root, int data)
{
    if(root == nullptr) {
        //If the tree is empty, return a new node
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    //return the (unchanged) node pointer
    return root;
}

//Function to search a given key in a given BST
Node* searchNode(Node* root, int key)
{
    //Base class: root is null or key is present at root
    if (root == nullptr || root->data == key)
    {
        return root;
    }

    //Key is greater than root's key
    if (root->data < key)
    {
        return searchNode(root->right, key);
    }

    //Key is smaller than root's key
    return searchNode(root->left, key);
}

//Function to find the inorder successor
Node* minValueNode(Node* node)
{
    Node* current = node;
    //Loop down to find the leftmost leaf
    while(current && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

//Function to delete a node
Node* deleteNode(Node* root, int data)
{
    if (root == nullptr)
        return root;
    
    //If the data to be deleted is smaller than the root's 
    //data, then it lies in the left subtree
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    //If the data to be deleted is greater than the root's
    //data, then it lies in the right subtree
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    //If data is same as root's data, then this is the new node to be deleted
    else 
    {
        //node with only one child or no child
        if (root->left == nullptr) 
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //Node with two children: Getting the inorder successor
        //(smallest in the right subtree)
        Node* temp = minValueNode(root->right);

        //Copy the inorder successor's content to this node
        root->data = temp->data;
        
        //Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
    
}

//Function to do inorder traversal of BST
void inorderTraversal(Node* root)
{
    if (root != nullptr){
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main(){

    Node* root = nullptr;
    //Creating a BST
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    root = insertNode(root, 25);
    root = insertNode(root, 45);
    root = insertNode(root, 65);
    root = insertNode(root, 75);

    //Print the inorder traversal of a BST
    std::cout << "Inorder traversal of the given Binary Search Tree is: ";
    inorderTraversal(root);
    std::cout << std::endl;

    //Search a key in BST
    Node* found = searchNode(root, 25);
    std::cout << std::endl;
    std::cout << "Searching for 25..." << std::endl;
    //Check if the key is found or not
    if (found != nullptr)
    {
        std::cout << "Node 25 found in the BST." << std::endl;
    }
    else
    {
        std::cout << "Node 25 not found in the BST." << std::endl;
    }

    std::cout << std::endl;
    //Deleting a node in BST
    root = deleteNode(root, 20);
    std::cout << "After deletion of 20: ";
    inorderTraversal(root);
    std::cout << std::endl;
    


    return 0;
}