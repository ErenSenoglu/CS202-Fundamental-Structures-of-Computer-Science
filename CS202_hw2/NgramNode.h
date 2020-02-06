#ifndef __NGRAMNODE_H
#define __NGRAMNODE_H
#include <string>
using namespace std;
class NgramNode{
private:
    string item;
    int occ;
    NgramNode* leftChildPointer;
    NgramNode* rightChildPointer;

public:
    NgramNode();
    ~NgramNode();
    void setItem(string& inputItem);
    string getItem();
    int getCount();
    void setCount(int n);
    void setLeftChildPtr(NgramNode* leftPtr);
    void setRightChildPtr(NgramNode* rightPtr);
    NgramNode* getLeftChildPtr();
    NgramNode* getRightChildPtr();
    void increaseCount();
};
#endif
