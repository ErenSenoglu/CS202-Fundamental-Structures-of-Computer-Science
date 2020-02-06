#include "OpenHashTable.h"
#include "chainHashTable.h"
#include "Item.h"
#include <iostream>
#include <string>
int main(){

    /*OpenHashTable table = OpenHashTable();
    //cout << "sa" <<endl;
    table.insertItem("Eren",2);
    table.insertItem("Cemal",3);
    table.insertItem("Batu",4);
    table.insertItem("selamun hello",5);
    table.printTable();
    cout << "sa" <<endl;
    table.deleteItem("Eren");
    table.printTable();
    cout << "as" <<endl;
    table.insertItem("Eren",2);
    table.printTable();

    Item x = table.retrieveItem("sa");
    cout << x.amount << endl;
    */
    chainHashTable table = chainHashTable();
    cout << "Yonetim" << endl;
    table.insertItem("Eren",2);
    cout << "Yonetim2" << endl;
    table.printTable();
    table.insertItem("Cemal",3);
    table.printTable();
    table.insertItem("Batu",4);
    table.insertItem("selamun hello",5);
    table.printTable();
    return 0;
}
