//
//  MergeSort.h
//  Header File for SelectionSort class
//

#ifndef __Sorting__MergeSort__
#define __Sorting__MergeSort__

#include <iostream>

struct arrayWithLength{
        int length;
        int *arr;
};

class MergeSort {
public:
        MergeSort(); // constructor
        
        // read in a list of values from stdin
        void readList();
        
        // sort function
	void Sort(int low, int high, int *arr);       
        // print the array
        void printArray();
	
	void sort();
	
	void Split_Array(int low, int high, int *arr);

        
private:
        arrayWithLength sortArray;
	
};

#endif /* defined(__Sorting__MergeSort__) */

