/* 
 * File:   treeNode.cpp
 * Author: damien
 * 
 * Created on 7 September 2014, 10:00 PM
 */

#include <string.h>

#include "treeNode.h"

treeNode::treeNode() {
}


treeNode::treeNode(string word){
    this->word = word;
}

treeNode::treeNode(string word, int key){
    this->word = word;
    this->key = key;
}


treeNode::treeNode(const treeNode& orig) {
}

treeNode::~treeNode() {
}

void treeNode::increment() {
    wordCount++;
}

int treeNode::compare(string word) {
    return strcmp(this->word.c_str(), word.c_str());
}



