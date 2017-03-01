// 
//  MergeSort.cpp
//  Sorts integers using the MergeSort algorithm


#include "sort3.h"

using namespace std;

MergeSort::MergeSort(){ // constructor
        sortArray.length = 0;
        sortArray.arr = NULL;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void MergeSort::readList(){
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
// function that splits an array into half 
void MergeSort::Split_Array(int low, int high, int *tempArray){
	 
	
	 int halfarraylength = (high+low)/2;
	 
	 // conditional that checks if the array is greater than size 1
	 if (low < high) {
		 
		Split_Array(low, halfarraylength, tempArray); // recursively splits the array into two more subarrays
		Split_Array(halfarraylength + 1, high, tempArray);// recursively splits the array into two more subarrays
		Sort (low, high, tempArray); // Calls sort function that sorts all broken down arrays
	 }
	 return;
}
void MergeSort::Sort(int low, int high, int *tempArray)
{
	int halfarraylength = (high+low)/2; 
	// temp values for easier manipulation of array
	int temp_counter = low; 
	int low_counter = low; 
	int high_counter = halfarraylength + 1; 
	
	// stops when all arrays have been checked and passed into the tempArray
	while ( (low_counter <= halfarraylength) && (high_counter <= high)) {
		
		// checks if one element of the low array is greater than one of the high 
		// in the given indeces. 
		if (sortArray.arr[low_counter] < sortArray.arr[high_counter]) {
			tempArray[temp_counter] = sortArray.arr[low_counter]; 
			low_counter++; 
		}
		// checks if one element of the high array is greater than one of the low 
		// in the given indeces. 
		else  {
			tempArray[temp_counter] = sortArray.arr[high_counter]; 
			high_counter++; 
		}
		temp_counter++; // moves position in which we are going to insert in the tempArray
	}
		
		if (low_counter > halfarraylength){ // if all the lower array has been checked
						   // fill the rest of the tempArray with the remaining
						   // values of the high array. 
			while (high_counter <= high){
				tempArray[temp_counter++] = sortArray.arr[high_counter]; 
				high_counter++;
			}
		}
		else {				// if all the high array has been checked
						   // fill the rest of the tempArray with the remaining
						   // values of the low array. 
			while (low_counter <= halfarraylength){
				tempArray[temp_counter++] = sortArray.arr[low_counter]; 
				low_counter++;
			}
		}
		
	// copies tempArray into the actual array
	for (int i = low; i <= high; i++) {
		sortArray.arr[i] = tempArray[i]; 
		
	}
	
}


// Main function that creates a temp array, calls split array that includes Sort, 
// and once the actual array has been updated, deletes the tempArray. 
void MergeSort::sort(){
	int *tempArray = new int[sortArray.length]; 
	Split_Array(0, sortArray.length -1, tempArray);
	delete [] tempArray; 

}

void MergeSort::printArray(){
        // prints out the integers in sorted order
	for (int i = 0; i < sortArray.length; i++) {
		cout << sortArray.arr[i] << endl; 
	}

}