#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "NgramTree.h"
#include "NgramNode.h"
using namespace std;
NgramTree::NgramTree() : rootPtr(NULL){
}

NgramTree::~NgramTree(){
    destroyTree(this->rootPtr);
}
void NgramTree::destroyTree(NgramNode* subTreePtr){
    if (subTreePtr != NULL)
    {
            destroyTree((subTreePtr)->getRightChildPtr());
            destroyTree((subTreePtr)->getLeftChildPtr());
            delete subTreePtr;
            subTreePtr = NULL;
    }
}
NgramNode* NgramTree::balancedAdd(NgramNode* rootPtr,string ngram){
    if (rootPtr == NULL){
        NgramNode* newNodePtr = new NgramNode(); // creating new node
        newNodePtr->setItem(ngram);
        return newNodePtr;
        }
    else
    {
        NgramNode* leftPtr = rootPtr->getLeftChildPtr();
        NgramNode* rightPtr = rootPtr->getRightChildPtr();
        if(rootPtr->getItem().compare(ngram) < 0){
            rightPtr = balancedAdd(rightPtr,ngram);
            rootPtr->setRightChildPtr(rightPtr);
        }
        else if(rootPtr->getItem().compare(ngram) == 0)
            rootPtr->increaseCount(); // Incrementing count
        else
        {
            leftPtr = balancedAdd(leftPtr, ngram);
            rootPtr->setLeftChildPtr(leftPtr);
        }
    }
    return rootPtr;
}
void NgramTree::addNgram(string ngram){
    //NgramNode* newNodePtr = new NgramNode(); // creating new node
    //newNodePtr->setItem(ngram);              // and setting its item
    transform(ngram.begin(), ngram.end(), ngram.begin(), ::tolower);
    this->rootPtr = balancedAdd(rootPtr,ngram);
}

void NgramTree::printNgramFrequencies(){
    cout <<"Total "<<this->nNo<<"-gram count is: "<< this->getTotalNgramCount() << endl;
    printInorder(this->rootPtr);
    /*cout <<"n-gram tree is complete: ";
    if(this->isComplete())
        cout<< "Yes" << endl;
    else
        cout<< "No" << endl;
    cout <<"n-gram tree is full: ";
    if(this->isFull())
        cout << "Yes" << endl;
    else
        cout << "No" <<endl;*/
    return;
}
void NgramTree::printInorder(NgramNode* subTreePtr){
    if (subTreePtr == NULL)
        return;

    /* first recur on left child */
    printInorder(subTreePtr->getLeftChildPtr());

    /* then print the data of node */
    cout << subTreePtr->getItem() << " appears "<< subTreePtr->getCount()<< " time(s)"<<endl;

    /* now recur on right child */
    printInorder(subTreePtr->getRightChildPtr());
}
void NgramTree::generateTree(string fileName,int n){
    fstream file;
    string word;
    this->nNo = n;
    //fileName=fileName+".txt";
    // opening file
    file.open(fileName.c_str());
    char c;
    // extracting words from the file
    while (file >> word)
    {
        int len = word.length();
        //cout << word << endl;
        if(len == n){
            //cout << "Words1: " << word << endl;
            this->addNgram(word);
            }
        else if(len > n){
            for(int i = 0; i <= len-n;i++){
                if(i == 0){
                    string add = word.substr(i,n);
                    //cout << "i: " << i << "n: " << n << "add: "<<add<<endl;
                    this->addNgram(add);
                    //cout << "Add1: " << add << endl;
                    }
                else{
                string add = word.substr(i,n);
                //cout << "Add: " << add << endl;
                //cout << "i: " << i << "n: " << n << "add: "<<add<<endl;
                this->addNgram(add);
                }
                //cout << "Words: " << word << endl;
            }
        }
    }
}
int NgramTree::getTotalNgramCount(){
    return getNodeCount(this->rootPtr);
}
int NgramTree::getNodeCount(NgramNode* root){
    if (root == NULL)
       return 0;

    int res = 1;
    res += getNodeCount(root->getLeftChildPtr());
    res += getNodeCount(root->getRightChildPtr());
    return res;
}
bool isComp (NgramNode* root,int index,int number_nodes)
{
    if (root == NULL)
        return (true);

    if (index >= number_nodes)
        return (false);

    return (isComp(root->getLeftChildPtr(), 2*index + 1, number_nodes) && isComp(root->getRightChildPtr(), 2*index + 2, number_nodes));
}
bool NgramTree::isComplete(){
    int number = this->getTotalNgramCount();
    bool res = isComp(this->rootPtr,0,number);
    return res;
}
bool isFullTree (NgramNode* root)
{
    // If empty tree
    if (root == NULL)
        return true;

    // If leaf node
    if ((root->getLeftChildPtr() == NULL) && (root->getRightChildPtr() == NULL))
        return true;

    // If both left and right are not NULL, and left & right subtrees
    // are full
    if ((root->getLeftChildPtr()) && (root->getRightChildPtr()))
        return (isFullTree(root->getLeftChildPtr()) && isFullTree(root->getRightChildPtr()));

    // We reach here when none of the above if conditions work
    return false;
}
bool NgramTree::isFull(){
    bool res = isFullTree(this->rootPtr);
    return res;
}


