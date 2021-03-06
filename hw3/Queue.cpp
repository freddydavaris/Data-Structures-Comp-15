/*
 * Queue.cpp
 *
 */

#include <iostream>
#include "Queue.h"

	//constructor
Queue::Queue(){
	 
	capacity = 10; 
	size = 0;
	front = 0; 
	back = 0;
	queue_array = new Student[capacity];
	
}

	// destructor
Queue::~Queue(){
	
	delete [] queue_array; 
}

	// enqueue a char onto at the back of the queue
void Queue::enqueue(Student c){
	
	if (size == capacity) {
		expand();  
	}
	//if (is_empty() == true){
	//	queue_array[0] = c; 
	//	back = (back + 1) % capacity;
	//	size++; 
	//}
	//else {
	queue_array[back] = c; 
	back = (back + 1) % capacity;
	size++; 
	//}
}

	// dequeue a char from the front of the queue
Student Queue::dequeue(){
	
	Student dequeued_student;

	dequeued_student = queue_array[front];
	front = (front + 1) % capacity;
	size--; 
	return dequeued_student;
}
	// returns true if there are no elements in the
	// queue, false if the queue has elements
bool Queue::is_empty(){
	
	if (front == back && size == 0)
		return true;
	else
		return false;
}


	// expand the circular queue
void Queue::expand(){
		
	int newSize = 2 * size;
	Student *temp = new Student[newSize];
	
	for (int i = 0; i <= size; i++) {
		temp[i] = queue_array[(front + i) % capacity];
	}
	front = 0; 
	back = capacity;
	delete [] queue_array; 
	queue_array = temp;
	capacity = capacity * 2; 
}

int Queue::getfront() { // helper function that 
		        // returns the index at which the front is. 
	return front; 
}

int Queue::getcapacity() { // helper function that 
		           // returns the capacity 
	return capacity; 
}

string Queue::getName(int pos) { // helper function that 
				 // returns the name at position "pos"
	return queue_array[pos].name;
}

int Queue::getSize() { // helper function that 
		       // returns the size
	return size; 
}