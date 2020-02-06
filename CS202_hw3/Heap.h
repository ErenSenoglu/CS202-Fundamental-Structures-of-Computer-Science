//constint MAX_HEAP = maximum-size-of-heap;
#include "request.h"// definition of KeyedItem
#include <iostream>
using namespace std;
class Heap {
public:
	Heap();
	Heap(int length);				// default constructor
	// copy constructor and destructor are supplied by the compiler

	bool heapIsEmpty() const;
	void heapInsert(Request& newItem);
	void heapInsert2(Request& newItem);
	void heapInsertEvent(Request& newItem);
	void heapDelete(Request& rootItem);
	void heapDeleteEvent(Request& rootItem);
	Request retrieve();
    Request* items ;	// array of heap items
    void heapPrint();
    void setMaxItems(int maxI);
    int size;
    int maxItems;
protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at
	void heapRebuild2(int root);
    void heapRebuildEvent(int root);     // index root into a heap

private:

	      // number of heap items

};
