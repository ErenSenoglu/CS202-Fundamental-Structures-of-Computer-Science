#include "chainHashTable.h"
chainHashTable::chainHashTable(){
    for(int i = 0; i < 53;i++){
        arr[i] = NULL;
    }
}
void chainHashTable::insertItem(string name,int amount){
    int hashVal = hashValue(name);
    Node* curr = arr[hashVal];
    if(arr[hashVal] == NULL){
        arr[hashVal] = new Node(name,amount);
        return;
    }
    if(arr[hashVal]->deleted == 1){
        arr[hashVal]->name = name;
        arr[hashVal]->amount = amount;
        return;
    }
    cout << "Hash Value: " << hashVal<<endl;
    while(curr->next != NULL ){
            curr = curr->next;
            if(curr->deleted == 1){
                curr->name = name;
                curr->amount = amount;
            }
    }
        curr->next = new Node(name,amount);
        cout << "bitti" << endl;
}
int chainHashTable::hashValue(string name){
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
void chainHashTable::deleteItem(string name){
    int index = hashValue(name);
    Node* curr = arr[index];
    while(curr != NULL){
        if(curr->name == name)
            break;
        curr = curr -> next;
    }
    if(curr == NULL)
        cout << "Item not found" << endl;
    else
        curr->deleted = 1;
}
void chainHashTable::printTable(){

    cout << "orospu cocugu" << endl;
    for(int i = 0; i < 53 ; i++){
        Node* curr = arr[i];
        cout << "i: " << curr->name << endl;
        while(curr != NULL){
            cout << "sa" << endl;
            cout << "ananin ami : " << curr->name << endl;
            curr = curr->next;

            }
    }
}
