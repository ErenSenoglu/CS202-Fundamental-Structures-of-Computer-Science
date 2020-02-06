#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "sorting.h"
/**
* Title : Algorithm Efficiency and Sorting
* Author : Eren Þenoðlu
* ID: 21702079
* Section : 1
* Assignment : 1
* Description : Implementations of sorting algorithms.
*/
using namespace std;
void insertionSort(int *arr, int size, int &compCount, int &moveCount){
    for(int unsorted = 1; unsorted < size; ++unsorted) {
        int nextItem = *(arr+unsorted);
        moveCount++;
        int loc = unsorted;

    for( ;(loc > 0 ) && (*(arr+(loc-1)) > nextItem);--loc){
        *(arr+loc) = *((arr+loc)-1);
        moveCount++;
        compCount++;
        //cout << "Index : "<< unsorted<<" Count : " << compCount << endl;
    }
    if(loc != 0)
        compCount++;
    *(arr+loc) = nextItem;
    moveCount++;
}
}
void insertionSort(int *arr, int first,int last, int &compCount, int &moveCount){
    for(int unsorted = first+1; unsorted < last+1; ++unsorted) {
        int nextItem = *(arr+unsorted);
        moveCount++;
        int loc = unsorted;

    for( ;(loc > first ) && (*(arr+(loc-1)) > nextItem);--loc){
        *(arr+loc) = *((arr+loc)-1);
        moveCount++;
        compCount++;
        //cout << "Index : "<< unsorted<<" Count : " << compCount << endl;
    }
    if(loc != 0)
        compCount++;
    *(arr+loc) = nextItem;
    moveCount++;
}
}
void printArray(int *arr, int size){
    for(int i = 0; i < size ;i++){
        int item = *(arr+i);
        cout << item << " " ;
    }
    cout << "" << endl;
}
void swap1(int *a, int *b){
    int c = *b;
    *b = *a;
    *a = c;
}
void partition1(int *arr, int f, int l, int &pivotIndex, int &compCount, int &moveCount){
    //choosePivot(arr, first, last);

    int pivot = *(arr+f);
    moveCount++;

    //printArray(arr,(l-f));
    int lastS1 = f;
    int firstUnkown = (f+1);

    for(; firstUnkown <= l; ++firstUnkown){
        ++compCount;
        if (*(arr+firstUnkown) < pivot) {
            ++lastS1;
            swap1((arr+firstUnkown), (arr+lastS1));
            moveCount = moveCount + 3;
        }
    }

    swap1((arr+f), (arr+lastS1));
    moveCount = moveCount + 3;
    pivotIndex = lastS1;
}

void quickSort(int *arr, int f ,int l, int &compCount, int &moveCount){
    int pivotIndex;

    if(f < l){
        partition1(arr, f, l, pivotIndex,compCount,moveCount);

        quickSort(arr,f,pivotIndex-1,compCount,moveCount);
        quickSort(arr,pivotIndex+1,l,compCount,moveCount);
    }
}
void hybridSort(int *arr, int first, int last,int &compCount, int &moveCount){
    int pivotIndex;

    if(last - first + 1 <= 10)
        insertionSort(arr,first,last,compCount,moveCount);
    else{
        partition1(arr, first, last, pivotIndex,compCount,moveCount);

        hybridSort(arr,first,pivotIndex-1,compCount,moveCount);
        hybridSort(arr,pivotIndex+1,last,compCount,moveCount);
    }
}
void hybridSort(int *arr, int size, int &compCount, int &moveCount){
    int last = size-1;
    int first = 0;
    hybridSort(arr,first,last,compCount,moveCount);

}

void performanceAnalysis(){
    int c1,m1,c2,m2,c3,m3;
    int length[9] = {3000,4500,6000,7500,9000,10500,12000,13500,15000};
    clock_t start,finish;
    double time_taken;
    double timeEl[27];
    int mCount[27];
    int cCount[27];
    c1 = c2 = c3 = m1 = m2 = m3 = 0;
    int arr1[15000];
    int arr2[15000];
    int arr3[15000];
    int x;
    int index = 0;
    for(int i = 0 ; i < 9; i++){

        for(int k = 0; k < length[i]; k++){
            x = rand() % 30000;
            arr1[k] = x;
            arr2[k] = x;
            arr3[k] = x;
            }
        start = clock();
        quickSort(arr1,0,length[i]-1,c1,m1);
        finish = clock();
        time_taken = double(finish - start) / double(CLOCKS_PER_SEC)*1000;
        timeEl[index]=time_taken;
        cCount[index]=c1;
        mCount[index]=m1;
        index++;

        start = clock();
        insertionSort(arr2,length[i],c2,m2);
        finish = clock();
        time_taken = double(finish - start) / double(CLOCKS_PER_SEC)*1000;
        timeEl[index]=time_taken;
        cCount[index]=c2;
        mCount[index]=m2;
        index++;

        start = clock();
        hybridSort(arr3,length[i],c3,m3);
        finish = clock();
        time_taken = double(finish - start) / double(CLOCKS_PER_SEC)*1000;
        timeEl[index]=time_taken;
        cCount[index]=c3;
        mCount[index]=m3;
        index++;

        m1 = 0;
        c1 = 0;
        m2 = 0;
        c2 = 0;
        m3 = 0;
        c3 = 0;
    }

    //printArray(arr1,15);
    //printArray(arr2,15);
    //printArray(arr3,15);

    cout << "-----------------------" << endl;


    cout << "Part a - Time analysis of Quick Sort" << endl;
    cout << "-----------------------" << endl;
    cout << setw(15) << left << "Array Size" << setw(15)<< left << "Time elapsed" << setw(15) << left << "compCount" << setw(15) << left << "moveCount"<<endl;

    for(int a = 0 ; a < 25 ; a=a+3){
        cout << setw(15) << left << length[a/3];
        cout << setw(9) << left << timeEl[a] << setw(7) << left <<" ms";
        cout << setw(15) << left << cCount[a];
        cout << setw(15) << left << mCount[a]<<endl;
    }
        //Resetting values

        //delete [] arr2;

    cout << "-----------------------" << endl;




    cout << "Part b - Time analysis of Insertion Sort" << endl;
    cout << "-----------------------" << endl;
    cout << setw(15) << left << "Array Size" << setw(15)<< left << "Time elapsed" << setw(15) << left << "compCount" << setw(15) << left << "moveCount"<<endl;



    for(int b = 1; b < 26 ; b= b+3){
        cout << setw(15) << left << length[(b-1)/3];
        cout << setw(9) << left << timeEl[b] << setw(7) << left <<" ms";
        cout << setw(15) << left << cCount[b];
        cout << setw(15) << left << mCount[b]<<endl;
    }
        // Resetting values


    cout << "-----------------------" << endl;




    cout << "Part c - Time analysis of Hybrid Sort" << endl;
    cout << "-----------------------" << endl;
    cout << setw(15) << left << "Array Size" << setw(15)<< left << "Time elapsed" << setw(15) << left << "compCount" << setw(15) << left << "moveCount"<<endl;


    for(int c = 2 ; c < 27 ; c = c+3){
        cout << setw(15) << left << length[(c-2)/3];
        cout << setw(9) << left << timeEl[c] << setw(7) << left <<" ms";
        cout << setw(15) << left << cCount[c];
        cout << setw(15) << left << mCount[c]<<endl;

    }


     cout << "-----------------------" << endl;

}

