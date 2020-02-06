#include "OpenHashTable.h"
#include <iostream>
#include <string>
OpenHashTable::OpenHashTable(){
    sizeCur = 0;
}
void OpenHashTable::insertItem(string name, int amount){
    if(sizeCur < MAX_SIZE){
        //cout << "Selamun aleyküm" <<endl;
        int hashVal = hashValue(name);
        int probe = 1;
        Item temp = Item(amount,name);
        while(!(arr[hashVal].name == "" )&& !(arr[hashVal].deleted == 1)){
            hashVal = hashVal + (probe*probe);
            probe++;
            if(hashVal >= MAX_SIZE)
                hashVal = hashVal % MAX_SIZE;
            //cout << "Index is : " << hashVal << endl;
        }
        arr[hashVal] = temp;
        sizeCur++;
    }
    else
        cout << "Not enough size for another item" << endl;
}
int OpenHashTable::hashValue(string name){
    const int p = 31;
    const int m = 50;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : name) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

void OpenHashTable::deleteItem(string name){
    int index = hashValue(name);
    int probe = 1;
    while(!(arr[index].name == name ) && !(arr[index].deleted == 0) ){
        index = index + (probe*probe);
        probe++;

        if(index >= MAX_SIZE)
            index = index % MAX_SIZE;
    }
    if((arr[index].name == name ) && (arr[index].deleted == 0) ){
        arr[index].deleted = 1;
        sizeCur--;
    }
    else
        cout << "Item has not found"<< endl;
}
void OpenHashTable::printTable(){
    for(int i = 0; i < 53;i++){
        if(arr[i].name != "" && arr[i].deleted != 1)
            cout <<i <<": "<< arr[i].name << " = "<<arr[i].amount << endl;
    }
}
Item OpenHashTable::retrieveItem(string name){
    int index = hashValue(name);
    int probe = 1;
    while(!(arr[index].name == name ) && !(arr[index].deleted == 0) ){
        index = index + (probe*probe);
        probe++;

        if(index >= MAX_SIZE)
            index = index % MAX_SIZE;
    }
    if((arr[index].name == name ) && (arr[index].deleted == 0) ){
        return arr[index];
    }
    else{
        cout << "Item has not found"<< endl;
        return Item();
    }
}
