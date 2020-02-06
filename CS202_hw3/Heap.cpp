#include "Heap.h"
#include "request.h"
#include <iostream>
using namespace std;

Heap::Heap():items(NULL),size(0),maxItems(0){
    //cout << "Heap is created" << endl;
}
Heap::Heap(int length){
    items = new Request[length];
    maxItems = length;
    size = 0;
}
void Heap::setMaxItems(int maxI){
    maxItems = maxI;
    //cout <<"yapma banaa "<<endl;
}
bool Heap::heapIsEmpty() const {
	return (size == 0);
}
void Heap::heapInsert(Request &newItem){

	if (size >= maxItems)
		cout << "Heap is full." << endl;

	// Place the new item at the end of the heap
	items[size] = newItem;
	// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1)/2;
	while ( (place > 0) && (items[place].priority > items[parent].priority) ) {
		Request temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++size;
}
void Heap::heapInsert2(Request &newItem){

	if (size >= maxItems)
		cout << "Heap is full." << endl;

	// Place the new item at the end of the heap
	items[size] = newItem;
	// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1)/2;
	while ( (place > 0) && ((items[place].priority > items[parent].priority)||((items[place].priority == items[parent].priority)&&(items[place].time < items[parent].time)) )) {
		Request temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++size;
}
void Heap::heapInsertEvent(Request &newItem){

	if (size >= maxItems)
		cout << "Heap is full." << endl;

	// Place the new item at the end of the heap
	items[size] = newItem;
	// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1)/2;
	while ( (place > 0) && (items[place].time < items[parent].time) ) {
		Request temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++size;
}

void Heap::heapDelete(Request& rootItem) {
	if (heapIsEmpty())
		cout << "HeapException: Heap empty" << endl;
	else {
		rootItem = items[0];
		items[0] = items[--size];
		heapRebuild2(0);
	}
}
void Heap::heapPrint(){
    for(int i=0 ; i < size; i++){
        cout << "Item ID is :"<<items[i].id << " Prio :"<< items[i].priority<<" Time: "<<items[i].time<< endl;
    }
}
Request Heap::retrieve(){
    return items[0];
}
void Heap::heapDeleteEvent(Request& rootItem) {
	if (heapIsEmpty())
		cout << "HeapException: Heap empty" << endl;
	else {
		rootItem = items[0];
		items[0] = items[--size];
		heapRebuildEvent(0);
	}
}
void Heap::heapRebuild(int root) {
	int child = 2 * root + 1; 	// index of root's left child, if any
	if ( child < size ) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < size) &&
		     (items[rightChild].priority >items[child].priority) )
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if ( items[root].priority < items[child].priority ) {
			Request temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
}
}
void Heap::heapRebuild2(int root) {
	int child = 2 * root + 1; 	// index of root's left child, if any
	if ( child < size ) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < size) &&
		     (items[rightChild].priority >items[child].priority) )
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if (( items[root].priority < items[child].priority )||((items[root].priority == items[child].priority)&&items[root].time > items[child].time)) {
			Request temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild2(child);
		}
}
}
void Heap::heapRebuildEvent(int root) {
	int child = 2 * root + 1; 	// index of root's left child, if any
	if ( child < size ) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < size) &&
		     (items[rightChild].time <items[child].time) )
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if ( items[root].time > items[child].time ) {
			Request temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuildEvent(child);
		}
}
}
