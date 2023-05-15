#include <iostream>
#include "Node.h"

int main()
{
	Node *n = new Node(10);
	std::cout << n->getData() << "\n";
	Node *n2 = new Node(20);
	n->setLeft(n2);
	Node *n4 = new Node(60);
	Node *n5 = new Node(70);
	Node *n3 = new Node(50, n4, n5);
	n->setRight(n3);
	Node *n6 = new Node(30);
	n2->setLeft(n6);
	Node *n7 = new Node(40);
	n6->setLeft(n7);
}
