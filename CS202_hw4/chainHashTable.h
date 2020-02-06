#ifndef __CHAINHASHTABLE
#define __CHAINHASHTABLE
#include <string>
#include "Item.h"
#include "Node.h"
using namespace std;
class chainHashTable{
public:
    chainHashTable();
    int hashValue(string name);
    Item retrieveItem(string name);
    void insertItem(string name, int amount);
    void deleteItem(string name);
    void printTable();

    Node* arr[53];


};
#endif // __CHAINHASHTABLE
