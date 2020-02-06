#include "Node.h"
Node::Node(){
}
Node::Node(string name, int amount){
    this->name = name;
    this->amount = amount;
    deleted = 0;
    next = NULL;
}


