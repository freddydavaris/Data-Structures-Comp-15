# ReadMe for COMP 15 HW5
## Sorting Assignment 

Every assignment you submit you will include a ReadMe file. The name
could be ReadMe, readme, Read-me.txt, readME, ReadMe.md (the “.md”
stands for “markdown,” which allows lightweight formatting) or almost
anything you like that has the word read followed by the word me. Exact
spelling is not important, the contents are.

The purpose of the ReadMe file is the same as the little paper insert
you get in a new appliance -- to give the reader an introduction and
overview of the product.

Your ReadMe file for the assignments **must** include:

1.  The purpose of your program

2.  List of files with one/or two-line summary

3.  How to compile it (saying "use included Makefile" is ok)

4.  Outline of data structure (depending on the assignment)

5.  Outline of algorithm (depending on the assignment)

6.  A list of people who materially helped you on the assignment. If
    you worked with a friend and you shared ideas, you need to 
    list that person, e.g., "Josh Whedon helped me on this assignment".
    You do not need to list TAs, or professors, but you may feel free
    to do so.

The ReadMe file shows the reader, in a quick glance, what the program is
about and gives a general idea of how it works. For short programs the
readme file will be short, for more complicated programs the readme file
will be longer.

Use outline form rather than long discursive paragraphs. A ReadMe file
is an overview.

There is no correct readme format; within these guidelines, devise your
own style.

1: The purpose of these programs is to sort unsorted arrays of integers using
three different types of sorts. I used insertion, selection and merge sort. 

2: MergeSort.cpp: Uses a merge sort implementation to sort an unsorted array. Uses a 
MergeSort.h file and runs through main3.cpp

  InsertionSort.cpp: Uses an insertion sort implementation to sort an unsorted array. Uses 
an InsertionSort.h file and runs through main2.cpp 

  SelectionSort.cpp: Uses a selection sort implementation to sort an unsorted array. Uses 
a SelectionSort.h file and runs through the main1.cpp

3: Use Makefile to compile

4: In this program i use arrays that are rearranged for the first two sort to create the
final sorted array and for the third sort (mergesort) we use a temp array in which we
copy in the sorted array and then pass it in to the original array and print it out.

5: 	InsertionSort: This sort compares the checked element with all of its previous elements and swaps it
everytime it is smaller than any of the preceding ones using one input function, one sort function and one
print function.

	SelectionSort: This sort goes through every element of the array, compares it to all of the elements to 
its right and if any value is smaller than the checked value, it swaps them and goes to the next element of the array. 
It uses one input function, one sort function and one print function. 

	MergeSort: This sort splits the array into subarrays until all arrays are split into 1-element arrays, and 
recursively compares adjacent arrays and sorts them back into their original size. This sort uses a split function, 
a sort function, an input function, a print function and finally another sort function that calls split and sort together. 

6. (-)

