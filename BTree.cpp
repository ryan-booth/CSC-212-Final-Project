// Program to create a B tree
#include "BTree.hpp"

/*
 *  BTNode Class Functions
 */

 BTNode::BTNode(int order, bool leaf){
    //Sets order, data, and leaf flag based on input parameters
    this->m = order;
    this->leaf = leaf;
    //Based on the order, the length of the keys pointer array and child pointer array are set to their max capacity
    this->keys = new std::pair<std::string,int>[2 * m - 1];
    this->children = new BTNode* [2 * m];
    this->numKeys = 0; //Set initial key count to 0
}

void BTNode::insertRec(std::string word)
{
    //Check if node is a leaf node
    if (leaf == true)
    {
        //Node is a leaf node
        int i = numKeys - 1; //Create a counter starting from the highest key
        //Make room for new key to be inserted
        while (i >= 0 && keys[i].first >= word)
        {
            //Check if the word is repeated in the node
            if(keys[i].first == word){
                //Increment the counter by 1 and return
                keys[i].second += 1;
                return;
            }

            keys[i + 1] = keys[i]; //Push back keys
            i--;
        }
        keys[i + 1] = std::make_pair(word, 1); //Insert new key at index
        numKeys = numKeys + 1; //Increment the number of keys
        return;
    }
    //Node is not a leaf node
    int i = numKeys - 1; //Create a counter starting from the highest key
    //Check each key in the node for the word until we find the index where the word is >= to the keys
    while (i >= 0 && keys[i].first >= word){
        //Check if the word is repeated in the node
        if(keys[i].first == word){
            //Increment the counter by 1 and return
            keys[i].second += 1;
            return;
        }
    }
    //Check if the child is full
    if (children[i + 1]->numKeys >= 2 * m - 1)
    {
        //Child is full
        split(i + 1, children[i + 1]); //Split the child

        //Determine which half of the split child gets the new key
        if (keys[i + 1].first < word){
            i++;
        }
    }
    children[i + 1]->insertRec(word); //Call insertion helper
    return;
}

void BTNode::split(int i, BTNode* child)
{
    BTNode* sibling = new BTNode(child->m, child->leaf); //Create new sibling node to child
    int middle = m - 1; //Determine the index of the middle key

    // Set sibling's keys equal to the upper half of child's keys
    for (int j = 0; j < middle; j++){
        sibling->keys[j] = child->keys[j+m];
    }

    //Check if child is an internal node
    if(child->leaf == false){
        //Child is an internal node
        //Set sibling's children equal to the upper half of child's children
        for(int j = 0; j < middle + 1; j++){
            sibling->children[j] = child->children[j+m];
        }
    }

    // Set the new number of keys in child and sibling
    child->numKeys = middle;
    sibling->numKeys = middle;

    //Create room for new child in the parent node
    for (int j = numKeys; j >= i + 1; j--){
        children[j + 1] = children[j]; //Push back children
    }

    children[i + 1] = sibling; //Set sibling as child of the parent node

    //Create room for new key in the parent node
    for (int j = numKeys - 1; j >= i; j--){
        keys[j + 1] = keys[j]; //Push back keys
    }

    keys[i] = child->keys[middle]; //Set middle key of child as new key in the parent node
    numKeys += 1; //Increment key count by 1
}

/*
 *  BTree Class Functions
 */

/*
 *  Private
 */

void BTree::insert(std::string word)
{
    //Check if the tree is empty
    if (!root)
    {
        //Tree is empty
        root = new BTNode(m, true); //Create a root node
        root->keys[0] = std::make_pair(word, 1);  //Set word as key for root node
        root->numKeys = 1;  //Increment the key count for the root
        return;
    }
    //Check if the root is full
    if (root->numKeys >= 2 * m - 1)
    {
        //Root is full
        BTNode* tmp = new BTNode(m, false); //Create new root node
        tmp->children[0] = root; //Set old root as the new root's child
        tmp->split(0, root); //Split the old root

        //Determine which child gets the new key
        int childIndex;
        //Check if the word is greater than the new root's key
        if (tmp->keys[0].first < word){
            //If so, insert to the right child
            childIndex = 1;
        }
        //If not insert to the left child
        childIndex = 0;
        tmp->children[i]->insertRec(word); //Call insertion helper
        root = tmp; //Set tmp as root
        return;
    }
    //Root is not full
    root->insertRec(word); //Call insertion helper
    return;
}

bool BTree::search(std::string word, BTNode* root){
//Base case
if(!root){
    //If there are no more nodes left to check return false
    std::cout << word << " was not found!" << std::endl;
    return false;
}

int key = 0; //Counter for key index
//Check each key in the node for the word until there are no more keys <= the word
while(key < root->numKeys && word >= root->keys[key].first){
    //If the word is found, return
    if(word == root->keys[key].first){
        std::cout << word << " appeared " << root->keys[key].second << " time(s)!" << std::endl;
        return true;
    }
    key++;
}

return this->search(word, root->children[key]); //Recursively search children
}

/*
 *  Public
 */

BTree::BTree(int order){
    this->root = nullptr; //Sets the root pointer
    this->m = order; //Sets the order of the B-Tree
}

BTree::~BTree(){

}

bool BTree::search(std::string word){
    return this->search(word, this->root); //Calls recursive search function
}