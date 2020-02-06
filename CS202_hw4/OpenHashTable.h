#include "Item.h"
#include <iostream>
#include <string>
using namespace std;
class OpenHashTable{
    public:
            const int MAX_SIZE = 53;

            OpenHashTable();

            int hashValue(string name);
            Item retrieveItem(string name);
            void insertItem(string name, int amount);
            void deleteItem(string name);
            void printTable();

            Item arr[53];
            int sizeCur;
};
