/* 
 * File:   binaryTree.h
 * Author: damien
 *
 * Created on 7 September 2014, 10:00 PM
 */

#ifndef BINARYTREE_H
#define	BINARYTREE_H

#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include "treeNode.h"

using namespace std;

class binaryTree {
    
public:
    binaryTree();
    binaryTree(const binaryTree& orig);
    virtual ~binaryTree();
    void insert(string);
    void insert (treeNode*&, string);
    void out(stringstream&);
    void rotateLeft(treeNode*&);
    void rotateRight(treeNode*&);
    friend class treeNode;
private:
    treeNode* root;
    void destroy(treeNode*);
    void inOrderTraversal(treeNode*, stringstream&);
   
};

#endif	/* BINARYTREE_H */

