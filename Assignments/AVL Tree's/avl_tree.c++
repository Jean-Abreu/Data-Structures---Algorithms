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
            Node* x = y->right;
            Node* T2 = x->left;

            //Performing the rotation
            x->right = y;
            y->left = T2;

            //Updating the heights
            y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
            x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

            return x;
        }

        //Left rotate
        Node* leftRotate(Node* x){
            Node* y = x->right;
            Node* T2 = y->left;

            //Performing the rotation
            x->left = x;
            x->right = T2;

            //Updating the heights
            x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
            y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

            return y;
        }

        //Inserting node and balancing the tree
        Node* insert(Node* node, int key){

        }

        //Find minimum node in the right subtree (for deletion)
        Node* getMinValueNode(Node* node){

        }

        //Deleting node and balancing the tree
        Node* remove(Node* node, int key){
           if(!root) return root;

           //1: Performing standard BST deletion
           if(key < root->key){
                root->left = remove(root->left, key);
           }
           else if(key > root->){
                root->right = remove(root->right, key);
           }
           else {
                //Node with one child or no child
                if (!root->left || !root->right){
                    Node* temp = root->left ? root->left : root->right;
                    delete root;
                    return temp;
                }

                //Node with two children: Get the inorder successor (smallest in right subtree)
                Node* temp = getMinValueNode(root->right);
                root->key = temp-> key;
                root->right = remove(root->right, temp->key);
           }

           //2: Updating Height
           root->height = 1 + max(getHeight(root->left), getHeight(root->right));

           //3: Getting balance factor
           int balance = getBalance(root);

           //4: Balance the tree
           //Left Left Case
           if(balance > 1 && getBalance(root->left) >= 0){
                return rightRotate(root);
           }

           //Left Right Case
           if(balance > 1 && getBalance(root->left) >= 0){
                root->left = leftRotate(root->left);
                return rightRotate(root);
           }

           //Right Right Case
           if(balance < -1 && getBalance(root->right) <= 0){
                return leftRotate(root);
           }

           //Right Left Case 
           if(balance < -1 && getBalance(root->right) > 0){
            root->right = rightRotate(root->right);
            return leftRotate(root);
       }


        }

        //Inorder Traversal
        void inorder(Node* root){

        }

    public: 
        Node* root;

        AVLTree() : root(nullptr) {}

        void insert(int key){

        }

        void remove(int key){
            root = remove(root, key);

        }

        void inorder(){

        }
};

//Driver main
int main(){
    AVLTree tree;
}