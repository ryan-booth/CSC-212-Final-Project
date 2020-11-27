// Program to create a B tree
#include "BTree.hpp"

treeNodes(){

    this->data = "";

    this->left = nullptr;

    this->right = nullptr;

    this->repeats = 0;

}

treeNodes(std::string data){

    this->data = data;

    this->left = nullptr;

    this->right = nullptr;

}

~treeNodes(){



}

// Function to determine the which side the new word will go to
// The function will return false if the new word is to the right and true when it is to the left
bool checkPosition(std::string word, std::string currWord){

    int i = 0;

    while (word[i] != '\0' && currWord[i] != '\0'){

        if (word[i] > currWord[i]){
            return false;

        }

        else if (word[i] < currWord[i]){
            return true;

        }

        i ++;

    }

    return false;

}

// Function to insert a new node to a B tree
treeNodes* insert(std::string word, treeNode* root){

    if (word == root->data){
        root->repeats ++;

        return NULL;

    }

    if (checkPosition){
        root->left = insert(data, root->left)

    }

    else{
        root->right = insert(data, root->right)

    }

    return root;

}

// Function to rotate a node to the left
treeNodes* leftRotate(treeNodes){



}

// Function to rotate a node to the right
treeNodes* rightRotate(treeNodes){



}

// Function to destroy the tree
void destroyTree(treeNodes* root){



}

// Function to detemine if a word is a repeat
bool isRepeat(std::string word, std::string currWord){



}

// Function to create a b tree
BTree();

// Function to delete a tree;
~BTree(){



}