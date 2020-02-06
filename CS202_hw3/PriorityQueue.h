#include "Heap.h"// ADT heap operations

class PriorityQueue {
public:
	// default constructor, copy constructor, and destructor
	// are supplied by the compiler

	// priority-queue operations:
	bool pqIsEmpty() const;
	void pqInsert(Request& newItem);
	void pqInsertEvent(Request& newItem);
	void pqDelete(Request& priorityItem);
	void pqDeleteEvent(Request& priorityItem);
	void print();
	Heap getHeap();
	Heap h;
};
