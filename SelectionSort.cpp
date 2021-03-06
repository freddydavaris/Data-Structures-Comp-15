// 
//  SelectionSort.cpp
//  Sorts integers using the SelectionSort algorithm


#include "SelectionSort.h"

using namespace std;

SelectionSort::SelectionSort(){ // constructor
        sortArray.length = 0;
        sortArray.arr = NULL;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void SelectionSort::readList(){
        int currentCapacity = 10;
        sortArray.arr = new int[currentCapacity];
        
        while (cin >> sortArray.arr[sortArray.length]) {
                ++sortArray.length;
                if (sortArray.length==currentCapacity) {
                        int *temp = new int[currentCapacity*2];
                        for (int i=0;i<currentCapacity;i++) {
                                temp[i] = sortArray.arr[i];
                        }
                        delete [] sortArray.arr;
                        sortArray.arr = temp;
                        currentCapacity *= 2;
                }
        }
}

void SelectionSort::sort(){
        // selection sort on sortArray
	int small;

	//goes through every element of the array
	for (int i = 0; i < sortArray.length; i++){
		small = i;
		for (int k = i; k < sortArray.length; k++) {
			//Searches for the smallest element in the array
			if (sortArray.arr[k] < sortArray.arr[small]) {
				small = k;
			}
		}
		
		int temp = sortArray.arr[small]; //temporary integers that stores smallest value
		sortArray.arr[small] = sortArray.arr[i]; // Swap smallest value with checked value
		sortArray.arr[i] = temp;
	}
}

void SelectionSort::printArray(){
        // prints out the integers in sorted order
	for (int i = 0; i < sortArray.length; i++) {
		cout << sortArray.arr[i] << endl; 
	}

}