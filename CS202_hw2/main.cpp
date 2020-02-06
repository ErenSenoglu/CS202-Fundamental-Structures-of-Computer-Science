#include "NgramTree.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int main( int argc , char ** argv){
    NgramTree tree;
    string fileName ( argv [1]);
    int n = atoi ( argv [2]);
    tree.generateTree(fileName,n);

    /*tree.addNgram("a");
    tree.addNgram("z");
    tree.addNgram("b");
    tree.addNgram("d");
    tree.addNgram("e");
    tree.addNgram("c");*/
    //tree.addNgram("c");
    //tree.addNgram("b");
    //tree.addNgram("c");
    //tree.addNgram("a");
    //tree.addNgram("d");
    //tree.addNgram("d");
    //string str = "sample";
    //str=str.substr(0,4);
    //cout << str << endl;
    tree.printNgramFrequencies();
    cout << n << "-gram tree is complete : "<< ( tree.isComplete () ? " Yes " : "No") << endl ;
    cout << n << "-gram tree is full : "<< ( tree.isFull () ? " Yes " : "No") << endl ;
    cout << "" <<endl ;
    tree.addNgram ("samp");
    tree.addNgram ("samp");
    tree.addNgram ("zinc");
    tree.addNgram ("aatt");
    tree.printNgramFrequencies();
    cout << n << "-gram tree is complete : "<< ( tree.isComplete () ? " Yes " : "No") << endl ;
    cout << n << "-gram tree is full : "<< ( tree.isFull () ? " Yes " : "No") << endl ;

    //tree.addNgram("b");
    //tree.addNgram("a");
    //tree.printNgramFrequencies();
    //cout << tree.isFull() << endl;
    return 0;
}
