/* Question 2: (20 points)
How can you determine if a given tree is a Binary Tree or a Binary Search Tree (BST)?
Provide a C++ program to check whether the tree follows the BST properties, where for
each node:
• The left subtree contains only values less than the node's value.
• The right subtree contains only values greater than the node's value.
• The above conditions apply recursively to all subtrees.
The program should efficiently verify if the given tree is a valid BST and return an
appropriate result.  */

#include <iostream>

//Node structure for Binary Tree
struct Node{
    int data;
    Node* left;
    Node* right;
};

//Function to create a new Node (root)
Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int data)
{
    if(root == nullptr){
        //If the tree is empty return a new node
        return createNode(data);
    }
    //If the left subnode of root is empty, insert the data as new node
    if(root->left == nullptr){
        root->left = insertNode(root->left, data);
    }
    //If there is a left subnode, we move towards the right
    else if(root->right == nullptr){
        root->right = insertNode(root->right, data);
    }
    //If both subnodes are full, we fill in the first left subnode available
    else{
        root->left = insertNode(root->left, data);
    }

    return root;
}

void displayBT(Node* root){
    if(root != nullptr){
        std::cout << root->data << " ";
        displayBT(root->left);
        displayBT(root->right);
    }
}

bool bst_or_bt(Node* root){
    //Base case 
    if(root == nullptr){
        return true;
    }
    //Checking to see if conditions are not met for BST
    if(root->left != nullptr && root->left->data >= root->data){
        return false;
    }

    if(root->right != nullptr && root->right->data <= root->data){
        return false;
    }

    return bst_or_bt(root->left) && bst_or_bt(root->right);
    

}

int main(){

    Node* root = nullptr;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    

    std::cout << "Binary Tree: ";
    displayBT(root);

    std::cout << std::endl;

    if(bst_or_bt(root)) {
        std::cout << "The tree is a Binary Search Tree." << std::endl;
    } else{
        std::cout << "The tree is NOT a Binary Search Tree." << std::endl;
    }

    return 0;
}