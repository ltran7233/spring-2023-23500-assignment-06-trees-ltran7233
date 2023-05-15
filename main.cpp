#include <iostream>
#include "BSTree.h"
#include "Node.h"

int main(){
	BSTree *t1 = new BSTree();
	t1->setup();
	std::cout << t1->get_debug_string() << std::endl;
}
