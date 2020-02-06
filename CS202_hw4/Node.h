#ifndef __NODE_H
#define __NODE_H
#include <string>
using namespace std;
class Node{


public:
    Node();
    Node(string name, int amount);
    string name;
    int amount;
    bool deleted;
    Node* next;

};
#endif

