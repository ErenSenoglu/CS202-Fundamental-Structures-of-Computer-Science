#include "PriorityQueue.h"
bool PriorityQueue::pqIsEmpty() const {
	return h.heapIsEmpty();
}

void PriorityQueue::pqInsert(Request& newItem){
	h.heapInsert2(newItem);
}
void PriorityQueue::pqInsertEvent(Request& newItem){
    h.heapInsertEvent(newItem);
}
void PriorityQueue::pqDeleteEvent(Request& priorityItem){
    h.heapDeleteEvent(priorityItem);
}
void PriorityQueue::pqDelete(Request& priorityItem) {
		h.heapDelete(priorityItem);
}
void PriorityQueue::print(){
    h.heapPrint();
}
Heap PriorityQueue::getHeap(){
    return h;
}
