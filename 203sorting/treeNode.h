/* 
 * File:   treeNode.h
 * Author: damien
 *
 * Created on 7 September 2014, 10:00 PM
 */

#ifndef TREENODE_H
#define	TREENODE_H

#include <cstdlib>
#include <string>
using namespace std;

class treeNode {
public:
    treeNode();
    treeNode(string);
    treeNode(string, int);
    treeNode(const treeNode& orig);
    void increment();
    int compare(string);
    virtual ~treeNode();
    friend class binaryTree;
private:
    treeNode * left = NULL;
    treeNode * right = NULL;
    string word;
    int wordCount = 1;
    int key;
    

};

#endif	/* TREENODE_H */

