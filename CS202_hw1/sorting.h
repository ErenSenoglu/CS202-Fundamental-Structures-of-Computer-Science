#ifndef __SORTING_H
#define __SORTING_H
/**
* Title : Algorithm Efficiency and Sorting
* Author : Eren Þenoðlu
* ID: 21702079
* Section : 1
* Assignment : 1
* Description : Header file of implemented methods.
*/
using namespace std;

    void insertionSort(int *arr, int size, int &compCount, int &moveCount);
    void printArray(int *arr, int size);
    void swap1(int *a, int *b);
    void partition1(int *arr, int f, int l, int &pivotIndex, int &compCount, int &moveCount);
    void quickSort(int *arr, int f ,int l, int &compCount, int &moveCount);
    void hybridSort(int *arr, int first, int last,int &compCount, int &moveCount);
    void hybridSort(int *arr, int size, int &compCount, int &moveCount);
    void performanceAnalysis();



#endif
