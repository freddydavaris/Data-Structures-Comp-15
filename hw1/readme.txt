Your ReadMe file for the assignments **must** include:

1.  The purpose of your program

The purpose of this program is through the implementation of classes, and dynamic arrays,
to create an program that deals out a deck of cards and has multiple functions.
  i.e. remove from index, insert at tail etc. 
  
2.  List of files with one/or two-line summary

  List_dynamic_array(); // constructor that initialises all int values and arrays

  ~List_dynamic_array(); // destructor that destroys all values and arrays
	
  void print_list(); // prints the list in human-readable form
	
  void print_list_int(); // prints the list as integers based
				// on rank and suit

  bool is_empty() { return cards_held==0; }

  void make_empty() { cards_held = 0; } // makes the list empty
	 
  void insert_at_head(Card c); // inserts at the beginning of the list
	
  void insert_at_tail(Card c); // inserts at the end of the list
	
  void insert_at_index(Card c, int index); // inserts at an index

  void replace_at_index(Card c, int index); // replaces the card
						// at an index
  Card card_at(int index); // returns the card at the index
	
  bool has_card(Card c); // returns true if the card is in the list
	
  bool remove(Card c); // removes the card
	
  Card remove_from_head(); // removes the beginning card
	
  Card remove_from_tail(); // removes the last card

  Card remove_from_index(int index); // removes the card at index
	
  int cards_in_hand() { return cards_held; }
	

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