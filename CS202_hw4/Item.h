#ifndef __ITEM
#define __ITEM

#include <string>
#include <iostream>
using namespace std;
class Item{
public:
    int amount;
    string name;
    bool deleted;
    Item(int amount, string name);
    Item();
};
#endif
