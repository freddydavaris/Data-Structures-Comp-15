1.  The purpose of your program

The purpose of this program is through the implementation of linked lists
to create an program that deals out a deck of cards and has multiple functions.
  i.e. remove from index, insert at tail etc. 
  
2.  	List_linked_list(); // constructor
	~List_linked_list();
	
	// copy constructor
	List_linked_list(const List_linked_list& source);
	
	// operator= overload
	List_linked_list operator =(const List_linked_list& source);
	
	//prints the list of cards
	void print_list();
	
	void print_list_int();
	
	//checks if head is empty
	bool is_empty() { return head==NULL; }

	// students must write the following functions in the .cpp file
	int cards_in_hand(); // returns the number of cards in the hand
	void make_empty(); // empties the list; head should equal NULL
	
	// inserts a card at the head
	// Should allow insert into an empty list
	void insert_at_head(Card c);

	// inserts a card at the tail (final node)
	// should allow insert into an empty list
	void insert_at_tail(Card c);

	// inserts a card at an index such that
	// all cards following the index will be moved farther
	// down the list by one.
	// The index can be one after the tail of the list
	// I.e., you can insert at index 0 into an empty list,
	// and you can insert at index 4 in a list with 4 nodes.
	// In the first case, the node inserted would become the head
	// In the second case, the node inserted would be inserted
	// after the current tail.
	void insert_at_index(Card c, int index);

	// replaces the card at index
	// A card at index must already exist
	void replace_at_index(Card c, int index);
	
	// returns the card at index.
	// allowed to crash if index is not in the list
	Card card_at(int index);
	
	// returns true if the card is in the list
	// returns false if the card is not in the list
	bool has_card(Card c);
	
	// removes the card from the list
	// Returns true if the card was removed
	// Returns false if the card was not in the list
	bool remove(Card c);

	// Removes the card from the head, and assigns the head
	// to head->next
	// Returns the card that was removed
	// Allowed to fail if list is empty
	Card remove_from_head();

	// Removes the card from the tail
	// Returns the card that was removed
	// Allowed to fail if the list is empty
	Card remove_from_tail();

	// Removes the card from index
	// Returns the card that was removed
	// Allowed to fail if index is beyond the end of the list
	Card remove_from_index(int index);

	Card_Node *head; // the head of the list
	

3.  How to compile it (saying "use included Makefile" is ok)

   In order to compile this program a Makefile has been provided
   
4.  Outline of data structure (depending on the assignment)
  
   In this project we used to classes, a card class and a hand class. The card
   class inlcuded all the 52 possible card combinations which where then dealt
   into the hand class that held many cards. 

5.  Outline of algorithm (depending on the assignment)

  The algorithm contains a main function that runs functions from the List_dynamic_array.cpp 
  program which is based on the List_dynamic_array.h and there are also two class structures,
  hand.cpp and hand.h and card.cpp and card.h that serve the purposes mentioned above. 