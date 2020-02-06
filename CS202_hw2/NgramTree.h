#ifndef __NGRAMTREE_H
#define __NGRAMTREE_H
#include "NgramNode.h"
#include <string>

class NgramTree{
public:
    NgramTree();
    ~NgramTree();
    void addNgram(std::string ngram);
    int getTotalNgramCount();
    void printNgramFrequencies();
    bool isComplete();
    bool isFull();
    void generateTree(std::string fileName, int n);

private:
    int getNodeCount(NgramNode* root);
    void destroyTree(NgramNode* subTreePtr);
    void printInorder(NgramNode* subTreePtr);
    NgramNode* balancedAdd(NgramNode* rootPtr,string newItem);
    int nNo;
    NgramNode* rootPtr;
};
#endif // __NGRAMTREE_H
