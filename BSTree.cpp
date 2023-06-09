#include <iostream>
#include "Node.h"
#include "BSTree.h"

BSTree::BSTree(){
  root = nullptr;
}




// Traversal - visit every node in the tree
// O(n)
std::string BSTree::traverse(Node *n){
  std::string a,b,c;

  if (n==nullptr){
    return "";
  } else {


    /*
     *  pre-order traversal
     1. process the node
     2. recurse to left subtree
     3. recurse to right subtree

     a = std::to_string(n->getData());
     b =  traverse(n->getLeft());
     c =  traverse(n->getRight());


     * post-order traversal

     1. recurse to left subtree
     2. recurse to right subtree
     3. process the node

     a =  traverse(n->getLeft());
     b =  traverse(n->getRight());
     c = std::to_string(n->getData());

    */

    /*
	in-order traversal

	1. recurse left subtree
	2. process node
	3. recurse right subtree
    */

    a = traverse(n->getLeft());
    b = std::to_string(n->getData());
    c = traverse(n->getRight());


return a + ", " + b+ ", " + c;


  }
}

std::string BSTree::get_debug_string(){
  return traverse(root);
}

/*
  if the BST is full/balanced
  this will behave like a binary search - remove 1/2
  the data set each time through
  so O(lgn) preformance

  IF THE tree isn't full/balanced it degenerates
  into a linked list and you only get O(n)

*/
int BSTree::search(int n){ // goes through the tree to find data value, if not found return error
  Node *current = root;


  while (current != nullptr){
    int node_val = current->getData();
    if (n == node_val){
      return node_val;
    } else if (n < node_val){
      current = current->getLeft();
    } else {
      current = current->getRight();
    }
  }
  throw TREE_ERR_NOTFOUND; // returning a not found value would be better

}

int BSTree::searchr(int val){ 
	return searchr(val, root);
}

int BSTree::searchr(int val, Node *p){ // the recursive call
	if (p == nullptr){
		throw TREE_ERR_NOTFOUND;
	}
	
	int node_val = p->getData();
	
	if (val == node_val){
		return node_val;
	}
	else if (val < node_val){
		return searchr(val, p->getLeft());
	}
	else {
		return searchr(val, p->getRight());
	}
}

/*
  if the BST is full/balanced
  this will behave like a binary search - remove 1/2
  the data set each time through
  so O(lgn) preformance

  IF THE tree isn't full/balanced it degenerates
  into a linked list and you only get O(n)
*/
void BSTree::insert(int n){
  Node *new_node = new Node(n);

  // special case if the tree is empty
  if (root == nullptr){
    root = new_node;
    return;
  }

  // search for the insertion point
  Node *current = root;
  Node *trailer = nullptr;
  while (current != nullptr){
    trailer = current; // catch the trailer up
    int val = current->getData();
    if (n == val){
      // update the node with the additional stuff
      return;
    } else if (n < val){
      current = current->getLeft();
    } else {
      current = current->getRight();
    }
  }
  // if we get here, trailer points to the
  // node above the new node's location
  if (n < trailer->getData()){
    trailer->setLeft(new_node);
  } else {
    trailer->setRight(new_node);
  }
}

/* recursive insert doesn't work

void BSTree::insertr(int n){
	insertr(n, root);
}

void BSTree::insertr(int n, Node *p){
	Node *new_node = new Node(n);
	if (p == nullptr){
    p = new_node;
    return;
  }

	int val = p->getData();
	if (n < val){
		insertr(n, p->getLeft());
	}
	else {
		insertr(n, p->getRight());
	}
}
*/

void BSTree::deleten(int val){
	if (root == nullptr){
		throw TREE_ERR_EMPTY;
	}
	
	Node *current = root;
  Node *trailer = nullptr;
  while (current->getData() != val){
  	trailer = current; // catch the trailer up
    if (current == nullptr){
    	throw TREE_ERR_NOTFOUND;
    } else if (val < current->getData()){
      current = current->getLeft();
    } else {
      current = current->getRight();
    }
  }
  
  if (current->getLeft() == nullptr && current->getRight() == nullptr){ // case 1
  	if (val < trailer->getData()){
      trailer->setLeft(nullptr);
    } else {
      trailer->setRight(nullptr);
    }
  }
  else if (current->getLeft() != nullptr && current->getRight() != nullptr){ // case 3
  	Node *smallest = current->getRight();
  	Node *strailer = nullptr;
  	int small = smallest->getData();
  	while (smallest != nullptr){
  		strailer = smallest;
  		small = strailer->getData();
  		smallest = smallest->getLeft();
  	}
  	current->setData(small);
		current->setRight(nullptr);
  }
  else { // case 2
  	if (current->getLeft() != nullptr){
			trailer->setLeft(current->getLeft());
			current->setLeft(nullptr);
		} else {
			trailer->setRight(current->getRight());
			current->setRight(nullptr);
		}
  }
}

int BSTree::treesum(Node *n){ // counts each node's value starting from the chosen node
  if (n==nullptr){
    return 0;
  } else {
    int value = n->getData();
    return value + treesum(n->getLeft())
      + treesum(n->getRight());
  }
}

int BSTree::treesum(){ // counts sum of the entire tree from the root
  return treesum(root);
}

int BSTree::countodds(Node *n){ // counts how many odd values are in the tree from the chosen node
  if (n==nullptr){
    return 0;
  } else {
    int data = n->getData();
    int value;
    if (data%2==0) {
      value = 0;
    } else {
      value = 1;
    }
    return value + countodds(n->getLeft())
      + countodds(n->getRight());
  }
}

int BSTree::countodds(){ // counts all the odd values of the entire tree starting from the root
  return countodds(root);
}
int BSTree::oddsum(Node *n){ // counts the sum of the odd nodes of the tree from the given node
  if (n==nullptr){
    return 0;
  } else {
    int data = n->getData();
    int value;
    if (data%2==0) {
      value = 0;
    } else {
      value = data;
    }
    return value + oddsum(n->getLeft())
      + oddsum(n->getRight());
  }
}

int BSTree::oddsum(){ // counts the sum of the odd nodes of the entire tree from the root
  return oddsum(root);
}

int BSTree::countLeaves(){
  Node *current = root;
  if (current == nullptr){
    return 0;
  } else {
    return countLeaves(current);
  }
}

int BSTree::countLeaves(Node *p){
  Node *current = p;

  if (current->getLeft() == nullptr && current->getRight() == nullptr){
    return 1;
  } else {
    return countLeaves(current->getLeft()) + countLeaves(current->getRight());
  }
}

int BSTree::height(){
  Node *current = root;
  if (current == nullptr){
    return 0;
  } else {
    return height(current);
  }
}

int BSTree::height(Node *p){
  Node *current = p;
  if (current == nullptr){
    return 0;
  } else {
    int left_h = height(current->getLeft());
    int right_h = height(current->getRight());
    if (left_h < right_h){
      return (right_h + 1);
    } else {
      return (left_h + 1);
    }
  }
}

void BSTree::setup(){ // tree example
  Node *n = new Node(10);
  root = n;
  n = new Node(20);
  root->setRight(n);
  Node *n2 = new Node(30);
  n->setRight(n2);
  n2 = new Node(15);
  n->setLeft(n2);
  n2 = new Node(5);
  root->setLeft(n2);
  n = new Node(3);
  n2->setLeft(n);
  n = new Node(8);
  n2->setRight(n);
}
