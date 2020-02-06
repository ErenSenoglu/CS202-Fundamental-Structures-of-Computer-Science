#include "sorting.h"
/**
* Title : Algorithm Efficiency and Sorting
* Author : Eren Þenoðlu
* ID: 21702079
* Section : 1
* Assignment : 1
* Description : Main method of the sorting algorithms.
*/
int main(){
        int c1,m1,c2,m2,c3,m3;
        c1 = c2 = c3 = m1 = m2 = m3 = 0;
        int a1[12] = {22, 11, 6, 7, 30, 2, 27, 24, 9,1, 20, 17};
        int a2[12] = {22, 11, 6, 7, 30, 2, 27, 24, 9,1, 20, 17};
        int a3[12] = {22, 11, 6, 7, 30, 2, 27, 24, 9,1, 20, 17};
        quickSort(a1,0,11,c1,m1);
        printArray(a1,12);

        insertionSort(a2,12,c2,m2);
        printArray(a2,12);

        hybridSort(a3,12,c3,m3);
        printArray(a3,12);

        performanceAnalysis();



    return 0;
}
