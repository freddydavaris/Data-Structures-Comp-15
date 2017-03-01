#include "List_dynamic_array.h"

#include <iostream>
#include <cassert>

using namespace std;

List_dynamic_array::List_dynamic_array()
{
       //initialize list and int variables
       
	cards = new Card[INITIAL_CAPACITY]; 
	cards_held = 0 ; 
	hand_capacity = INITIAL_CAPACITY;
}

List_dynamic_array::~List_dynamic_array()
{
        //delete list
	
	  delete [] cards;
}

// copy constructor
List_dynamic_array::List_dynamic_array(const List_dynamic_array& source) {
	// explicit copy constructor necessary because of cards array
	cards_held = source.cards_held;
	hand_capacity = source.hand_capacity;

	cards = new Card[hand_capacity];
	for (int i=0;i<cards_held;i++) {
		cards[i] = source.cards[i];
	}
}

// operator= overload
List_dynamic_array List_dynamic_array::operator =(const List_dynamic_array&
		source) {
	// explicit operator= overload necessary because of cards array
	Card *new_cards;

	// check for self-assignment -- return without doing anything
	if (this == &source) {
		return *this;
	}

	hand_capacity = source.hand_capacity;
	cards_held = source.cards_held;
	new_cards = new Card[hand_capacity];
	for (int i=0;i<hand_capacity;i++) {
		new_cards[i]=source.cards[i];
	}
	delete [ ] cards;
	cards = new_cards;
	return *this;
}

void List_dynamic_array::print_list()
{
	for(int i=0; i<cards_held; i++) {
		cards[i].print_card();
		if (i != cards_held-1) {
			cout << ",";
		} else {
			cout << "\n";
		}
	}
}

void List_dynamic_array::print_list_int()
{
	for(int i=0; i<cards_held; i++) {
		cards[i].print_card_int();
		if (i != cards_held-1) {
			cout << ", ";
		} else {
			cout << "\n";
		}
	}
}

void List_dynamic_array::insert_at_head(Card c)
{
        // Student writes code here
	// check if we need to expand, and expand if necessary
	if (cards_held >= hand_capacity) {
	  expand();
	}
	// move all items over one, starting from the last one
	for (int i = 0; i <= cards_held; i++) {
	cards[cards_held - i + 1] = cards[cards_held - i];
	}
	// insert the new card
	cards[0] = c;  
	// update cards_held
	cards_held++;
}

void List_dynamic_array::insert_at_tail(Card c)
{
        // Student writes code here
	// check if we need to expand, and expand if necessary
	if (cards_held >= hand_capacity) {
	  expand();
	}
	// insert the new card at the end
	cards[cards_held] = c; 
	// update cards_held
	cards_held++;
}

void List_dynamic_array::insert_at_index(Card c,int index)
{
	// if index is greater than cards_held, then fail
	assert(index <= cards_held);
	
	// Student writes code here
	// check if we need to expand, and expand if necessary
	if (cards_held >= hand_capacity) {
	  expand();
	}  
	// move all elements past the insertion point up one
	for (int i = 0; i < cards_held - index; i++) {
	cards[cards_held - i] = cards[cards_held - i - 1];
	}
	// insert the card
	cards[index] = c; 
	// update cards_held
	cards_held++; 
}

void List_dynamic_array::replace_at_index(Card c, int index) {
	// if index is greater than cards_held-1, then fail
	assert(index < cards_held);

	// Student writes code here
	// replace the card at index with c      
	cards[index] = c; 
}

Card List_dynamic_array::card_at(int index)
{
	Card x; 
	// if index is out of bounds, fail
	assert (index >= 0 && index < cards_held);
	
	// return the card at index
	// Student writes code heres
	x = cards[index];
	return x; 
}

bool List_dynamic_array::has_card(Card c) {
        // Student writes code here
        // loop through the cards and use the same_card()
        // method in Card.cpp to compare the cards
        // Returns true if the card is in the hand, false otherwise
	for (int i = 0; i < cards_held; i++) {
	  if (cards[i].same_card(c)) 
	     return true; 
	}
	return false; 
}

bool List_dynamic_array::remove(Card c)
{
	int x; 
	bool replace = false;
	// find the card and remove from the hand  
	for (int i = 0; i < cards_held; i++) {     
	  if (cards[i].same_card(c)) {
	      x = i; 
	      replace = true;
	      break;
	  }
	}  
	if (replace == true){
	  for (int y = x; y < cards_held; y++) {
	    cards[y] = cards[y+1];
	    
	  }
	cards_held--; 

	}  
	return replace; 
	
	// Returns true if the card was found and removed,
	// false otherwise
}

Card List_dynamic_array::remove_from_head()
{
	// if the list is empty, fail
	assert(cards_held > 0);

        // Student writes code here
        // remove the card at the head, and move all the other
        // cards back one spot
        // Returns the card that was removed
	assert(cards_held > 0);
	
	Card x = cards[0]; 

	for (int i = 0; i < cards_held; i++) {
	  cards[i] = cards[i+1];
	  }
	cards_held--;
	return x;
	

}

Card List_dynamic_array::remove_from_tail()
{
	Card x = cards[cards_held - 1];
	// if the list is empty, fail
	assert(cards_held > 0);

        // Student writes code here
	// removes the card that is at the tail, and returns it
	  
	// Returns the card that was removed
	cards_held--;
	return x;
}

Card List_dynamic_array::remove_from_index(int index)
{
	Card x = cards[index]; 
	// if the list is empty, fail
	assert(cards_held > 0);
	
	// if loc is outside of bounds, fail
	assert(index >= 0 && index < cards_held);

        // Student writes code here
	// similar to remove_from_head(), but
	// we remove the card at index
	for (int i = index; i < cards_held; i++) {
	  cards[i] = cards[i+1];
	  }
	// Returns the card that was removed
	cards_held--;
	return x;
}

void List_dynamic_array::expand()
{	
	// 1. create new list with twice the capacity

	Card* temp = new Card[hand_capacity*2]; 
	// 2. copy all cards to the new list
	if (temp == NULL) {        
	 cout << "Error " << endl;
	}                  
	
	for (int i = 0; i < cards_held; i++) {
	temp[i] = cards[i];
	}
	// 3. delete the old list
	delete [] cards;
	// 4. set cards variable to point to the new list
	cards = temp; 
	// 5. update hand_capacity
	hand_capacity = hand_capacity * 2;
	 
}
