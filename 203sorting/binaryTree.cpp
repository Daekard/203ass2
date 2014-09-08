/* 
 * File:   binaryTree.cpp
 * Author: damien
 * 
 * Created on 7 September 2014, 10:00 PM
 */

#include "binaryTree.h"

binaryTree::binaryTree() {
    root = NULL;
}

binaryTree::binaryTree(const binaryTree& orig) {
}

binaryTree::~binaryTree() {
    destroy(root);
}

void binaryTree::destroy(treeNode* current) {
    if (current != NULL){
        destroy(current->left);
        destroy(current->right);
        delete current;
    }
}

void binaryTree::out(stringstream& out) {
    inOrderTraversal(root, out);
}


void binaryTree::inOrderTraversal(treeNode* current, stringstream& out) {
    if (current != NULL){
        inOrderTraversal(current->left, out);    
        for (int i = 0; i < current->wordCount; i++){ out << current->word << " ";}
        cout << current->key << endl;
        inOrderTraversal(current->right, out);
    }else{
        return;
    }
}

void binaryTree::insert(string word) {
    if (root == NULL){
        root = new treeNode(word, rand());
    }else{
        this->insert(root, word);
    }
}

void binaryTree::rotateLeft(treeNode*& node) {  
    treeNode* newNode;
    newNode = node->right;
    node->right = newNode->left;
    newNode->left=node;
    node = newNode;
}

void binaryTree::rotateRight(treeNode*& node) {
    treeNode* newNode;
    newNode = node->left;
    node->left = newNode->right;
    newNode->right=node;
    node = newNode;
}

void binaryTree::insert(treeNode*& currentNode, string word) {
        int result = currentNode->compare(word);
   
        if (result < 0){
            if (currentNode->right == NULL){
                currentNode->right = new treeNode(word, rand());
            }
            else{
                insert(currentNode->right, word);
                if (currentNode->right->key > currentNode->key){
                    rotateLeft(currentNode);
                }
            }
        }else if(result > 0){
            if (currentNode->left == NULL){
                currentNode->left = new treeNode(word, rand());
            }
            else{
                insert(currentNode->left, word);
               
                if (currentNode->left->key > currentNode->key){
                    rotateRight(currentNode);
                }
            }
        }else{
            currentNode->increment();
        }
}


