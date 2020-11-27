// Header file to create a bit tree

#ifndef __RBTREE_H__
#define __RBTREE_H__

#include <iostream>
#include <fstream>
#include <cstring>
#include <iostream>
#include <graphics.h>

class treeNodes{

    private:
        std::sting data;
        treeNodes* left;
        treeNodes* right;
        int repeats;

    public:
        treeNodes();
        treeNodes(std::string data);
        ~treeNodes();

    friend class BTree;

}

class BTree{

    private:
        treeNodes* root;
        treeNodes* insert(std::string word);
        treeNodes* leftRotate(treeNodes);
        treeNodes* rightRotate(treeNodes);
        void destroyTree(treeNodes* root);
        bool checkPosition(std::string word, std::string currWord);

    public:
        BTree();
        ~BTree();

}

#endif