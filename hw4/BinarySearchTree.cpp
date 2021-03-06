/*
 * BinarySearchTree.cpp
 */

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

/* Constructs the Binary search tree
* Parameters: None
*/
BinarySearchTree::BinarySearchTree() {
	root = NULL; 
}

/* Post order deletes tree
* Parameters: None
*/
BinarySearchTree::~BinarySearchTree() {
	// walk tree in post-order traversal and delete
	post_order_delete(root);
}

/* Post order deletes tree
* Parameters: Node node;
*/
void BinarySearchTree::post_order_delete(Node *node) {
	if (node == NULL) { return; }
	post_order_delete(node->left);
	post_order_delete(node->right); 
	
	delete node;
}

// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source) {
	// use pre-order traversal to copy the tree
	root = pre_order_copy(source.root);
}

// assignment overload
BinarySearchTree& BinarySearchTree::operator=
		(const BinarySearchTree &source) {
	// check for self-assignment

	// delete current tree if it exists

	// use pre-order traversal to copy the tree

	// don't forget to "return *this"
	
	 if (this != &source) { // check for alias
		post_order_delete(root); // must delete original
		 
		 
		root = pre_order_copy(source.root);
	}
	return *this;
		
	}

/* Pre orded copies the BST
* Parameters: Node node;
*/
Node * BinarySearchTree::pre_order_copy(Node *node) {
	if (node == NULL) return NULL;
	Node *new_node = new Node();
	new_node->data = node->data;
	new_node->count = node->count; 
	
	new_node->left = pre_order_copy(node->left);
	new_node->right = pre_order_copy(node->right);
	return new_node; 
		

}

/* Finds the minimum value in the tree
* Parameters: None
* Returns an integer value
*/
int BinarySearchTree::find_min() {
	if (root == NULL) return INT_MIN;
	return find_min(root)->data;
}

/* Finds the minimum value in the tree
* Parameters: Node node
* Returns a node pointer
*/
Node *BinarySearchTree::find_min(Node *node) {
	if (node->left == NULL) { 
		return node; 
	}
	
	return find_min(node->left);
}

/* Finds the maximum value in the tree
* Parameters: Node node
* Returns an integer value
*/
int BinarySearchTree::find_max() {
	if (root == NULL) return INT_MAX;
	return find_max(root)->data;
}

/* Finds the maximum value in the tree
* Parameters: Node node
* Returns a node pointer
*/
Node *BinarySearchTree::find_max(Node *node) {
	if (node->right == NULL) { 
		return node; 
	}
	
	return find_max(node->right);
}

/* Checks if a value is already included
* in the tree and returns true if it is or
* false if it isn't. 
* Parameters: int value 
*/
bool BinarySearchTree::contains(int value) {
        if (root == NULL) return false;
	return contains(root, value);
}

/* Checks if a value is already included
* in the tree and returns true if it is or
* false if it isn't. 
* Parameters: int value and a Node node
*/
bool BinarySearchTree::contains(Node *node, int value) {
	if (node == NULL) {return false;}
	if (node->data == value) {return true;}
	else {
		return contains(node->left, value) || 
		       contains(node->right, value);
	}
	
	return false; 

}

/* Inserts a value into the tree 
* Parameters: int value 
*/
void BinarySearchTree::insert(int value) {
	insert(root,NULL,value);
}

/* Inserts a value into the tree 
* Parameters: int value and Node node and pointer
*/
void BinarySearchTree::insert(Node *node,Node *parent, int value) {

	if (root == NULL) {
		Node *temp = new Node;
		temp->data = value; 
		temp->count = 1; 
		
		temp->left = NULL; 
		temp->right = NULL;
		root = temp;
		return;
	}
	
	if (node == NULL) {
		Node *temp = new Node; 
		temp->data = value; 
		temp->count = 1; 
		
		if (parent->data > value) {
			temp->left = NULL;
			temp->right = NULL; 
			parent->left = temp;
		}
		else if (parent->data < value) {
			temp->left = NULL;
			temp->right = NULL; 
			parent->right = temp; 
		}
		return;
	}
	if (node->data == value){
		node->count = node->count + 1;
		return; 
	}
	if (node->data > value) {
		insert(node->left, node, value);
	} 
	else if (node->data < value) {
		insert(node->right,node, value);
	}
	
}

/* Removes a value from the tree. If it successfully removes
* it it returns true else it returns false
* Parameters: int value
*/
bool BinarySearchTree::remove(int value) {
	return remove(root,NULL,value);
}

/* Removes a value from the tree. If it successfully removes
* it it returns true else it returns false
* Parameters: int value and Node parent and node
*/
bool BinarySearchTree::remove(Node *node, Node *parent, int value) {

	Node *temp = NULL;
	Node *temp_parent; 
	if (node == NULL) return false;
        if (node->data == value) {
		if (node->count > 1){
			node->count =node->count - 1; 
			return true; 
		}
		else {
			if (node->left != NULL || node->right != NULL){ //not a leaf
				if (node->right != NULL){ 
 					if (node->left == NULL) {
 						if (parent == NULL) {
							temp = node;
							root = temp->right; 
							node->right = NULL;
							delete node; 
							return true;
						}
						else {
							parent->right = node->right; 
							delete node; 
							return true; 
						}
 					}
 					
					else {
							if (find_min(node->right) != node->right) {
								temp = find_min(node->right);
								temp_parent = find_parent(node->right, temp); 

								node->data = temp->data; 
								node->count = temp->count;
								temp_parent->left = temp->right;
								delete temp; 
								return true;
							}
							else {
								temp = node; 
								temp = temp->right; 
								node->count = temp->count;
								node->data = temp->data; 
								node->right = temp->right;
								delete temp; 
								return true;
							}

					}

					return remove(node->right, node, temp->data);
				}
				else {
					temp = node;  
					node = node->left;
					if (parent == NULL) {
						root = root->left; 
					}
					else if (parent->left == temp){
						parent->left = node; 
					}
					else {
						parent->right = node; 
					}
					delete temp;
					return true;
				}
			}
			else { // leaf
				if (parent == NULL) {
					root = NULL; 
				}
				else if (parent->left == node){ 
					parent->left = NULL; 
				}
				else {
					parent->right = NULL; 
				}
				delete node;
				return true;
			}
		}
	}	
	else {
		if (node->data > value) {
			return remove(node->left, node, value);
		} 
		else if (node->data < value) {
		
			return remove(node->right,node, value);
		}
	}	
	return false;
}

/*Returns and integer which represents the height of the tree
* Parameters: None
*/
int BinarySearchTree::tree_height() {
	return tree_height(root);
}

/*Returns and integer which represents the height of the tree
* Parameters: Node node
*/
int BinarySearchTree::tree_height(Node *node) {

    if(node == NULL){
        return -1;
    }

    int left_Height = tree_height(node->left);
    int right_Height = tree_height(node->right);

    if(left_Height > right_Height){
        return left_Height + 1;
    }
    else {
        return right_Height + 1;
    }
}
/*Returns and integer which represents the node count of the tree
* Parameters: None
*/
int BinarySearchTree::node_count() {
	return node_count(root);
}

/*Returns and integer which represents the node count of the tree
* Parameters: Node node
*/
int BinarySearchTree::node_count(Node *node) {
	if (node == NULL) return 0; 
	return 1 + node_count(node->left)
		 + node_count(node->right); 
}

/*Returns and integer which represents the total count of the tree
* Parameters: None
*/
int BinarySearchTree::count_total() {
	return count_total(root);
}

/*Returns and integer which represents the total count of the tree
* Parameters: Node node
*/
int BinarySearchTree::count_total(Node *node) {
	if (node == NULL) return 0;
	return (node->data * node->count)
		   + count_total(node->left)
		   + count_total(node->right);  
		
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() {
	printPretty(root, 1, 0, std::cout);
}

/*Returns a node pointer of the parent of the investigated
* node
* Parameters: Node node and child
*/
Node *BinarySearchTree::find_parent(Node *node,Node *child) {
	if (node==NULL) return NULL;

	// if either the left or right is equal to the child,
	// we have found the parent
	if (node->left==child || node->right == child) {
		return node;
	}

	// Use the binary search tree invariant to walk the tree
	if (child->data > node->data) {
		return find_parent(node->right,child);
	}
	else {
		return find_parent(node->left,child);
	}
}
