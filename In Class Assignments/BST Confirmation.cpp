//The problem at hand is to make a function that determine whether or not 
//a given tree is a BST or not

#include <iostream>

struct TreeNode{
    
    int val;
    TreeNode *left, *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};


//Funtction to insert a node into tree
TreeNode* insertIntoTree(TreeNode* root, int key){
    if(root == NULL){
        return new TreeNode(key);
    }
}



int main(){


    return 0;
}