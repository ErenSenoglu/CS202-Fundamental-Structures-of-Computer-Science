#include "Item.h"
Item::Item(int amountI, string nameI){
    amount = amountI;
    name = nameI;
    deleted = false;
}
Item::Item(){
    name = "";
}
