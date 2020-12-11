// Header file to create a bit tree

#ifndef __RBTREE_H__
#define __RBTREE_H__

#include <iostream>
#include <fstream>
#include <string>
#include <utility>

//Underlying node class similar to that of a BST
class BTNode{

    private:
        int m; //Order of the B-Tree
        std::pair<std::string,int>* keys; //Key array. Each key is a word/counter pair
        int numKeys; //Number of keys a node has
        BTNode** children; //Pointer for the child node of a key
        bool leaf; //Flag for whether this node is a leaf

    public:
        BTNode(int order, bool leaf); //Constructor
        ~BTNode();

        void insertRec(std::string word); //recursive insert for non-full nodes
        void split(int i, BTNode* child); //helper function to split a full node

    friend class BTree;

};

class BTree{

    private:
        BTNode* root; //Root pointer
        int m; //Order of the B-Tree

       void insert(std::string word, BTNode* root); //Inserts a word
       bool search(std::string word, BTNode* root); //Searches for a word

    public:
        BTree(int order); //Constructor
        ~BTree(); //Destructor

        bool search(std::string word); //Wrapper function for search
        void insert(std::string k); //Inserts a word into the tree
};

#endif