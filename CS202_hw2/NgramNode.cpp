#include "NgramNode.h"
#include <iostream>
using namespace std;
NgramNode::NgramNode(){
    leftChildPointer = NULL;
    rightChildPointer = NULL;
    occ = 0;
}
NgramNode::~NgramNode(){

}
void NgramNode::setItem(string& inputItem){
    occ++;
    item = inputItem;
    return;
}
string NgramNode::getItem(){
    return item;
}
int NgramNode::getCount(){
    return occ;
}
void NgramNode::setLeftChildPtr(NgramNode* leftPtr){
    leftChildPointer = leftPtr;
}
void NgramNode::setRightChildPtr(NgramNode* rightPtr){
    rightChildPointer = rightPtr;
}
NgramNode* NgramNode::getLeftChildPtr(){
    return leftChildPointer;
}
NgramNode* NgramNode::getRightChildPtr(){
    return rightChildPointer;
}
void NgramNode::setCount(int n){
    this->occ = n;
    return;
}
void NgramNode::increaseCount(){
    int cur = this->getCount();
    cur++;
    this->setCount(cur);
    return;
}
