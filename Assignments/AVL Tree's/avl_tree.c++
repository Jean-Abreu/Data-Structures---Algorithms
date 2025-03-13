// This assignment was broken into written responses and a couple
// of functions/methods for the AVL Tree structure. This file will go over
// those specific code functions necessary for the AVL Tree. We will start 
// off with the structure of the tree, then we will move towards the functionality.


#include <iostream>

//Node structure
struct Node {
    //Data and node pointers
    int key;
    Node* left;
    Node* right;
    //AVL needs to have height calculated to account for balance
    int height;

    //Constructor for the Node
    Node(int value) : key(value), left(nullptr), right(nullptr), height(1) {}

};

// AVL Tree Class
class AVLTree {
    private:
        //Function to get height of a node
        int getHeight(Node* node){

        }

        //Function to get balance factor
        int getBalance(Node* node){

        }

        //Right rotate
        Node* rightRotate(Node* y){

        }

        //Left rotate
        Node* leftRotate(Node* x){

        }

        //Inserting node and balancing the tree
        Node* insert(Node* node, int key){

        }

        //Find minimum node in the right subtree (for deletion)
        Node* getMinValueNode(Node* node){

        }

        //Deleting node and balancing the tree
        Node* remove(Node* node, int key){

        }

        //Inorder Traversal
        void inorder(Node* root){

        }

    public: 
        Node* root;
};